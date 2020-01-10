#ifndef BLOCKCHAIN_BLOCK_H
#define BLOCKCHAIN_BLOCK_H

#include <string>
#include <memory>
#include <ctime>
#include "keccak.h"
#include <sstream>
#include <iostream>

class block {
public:
    std::string m_hash;
    block *m_previous_block{};

    uint_fast64_t m_index, m_nonce;
    time_t m_timestamp{};

    void mine(uint_fast64_t difficulty);
    std::string calculate_hash();
    void update();
    explicit block(uint_fast64_t index);
};


#endif
