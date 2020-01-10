#include "block.h"

void block::mine(uint_fast64_t difficulty)
{
    char *hash_string_c = new char[difficulty + 1];

    uint_fast64_t rounds = 0;
    while(rounds < difficulty)
    {
        hash_string_c[rounds] = '0';
        ++rounds;
    }
    hash_string_c[difficulty] = '\0';

    std::string hash_string(hash_string_c);
    delete[] hash_string_c;

    do
    {
        ++m_nonce;
        m_hash = calculate_hash();
    }
    while (m_hash.substr(0, difficulty) != hash_string);
    std::cout << "block mined: " << m_hash.c_str() << std::endl;
}

std::string block::calculate_hash()
{
    std::stringstream string_stream;
    string_stream << m_index;
    string_stream << m_previous_block->m_hash;
    string_stream << m_timestamp;
    string_stream << m_nonce;
    Keccak keccak;
    return keccak(string_stream.str());
}

block::block(uint_fast64_t index) : m_index(index)
{
    m_nonce = 0;
    m_timestamp = time(nullptr);
}

void block::update() {
    m_hash = calculate_hash();
}
