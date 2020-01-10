#include "blockchain.h"

void blockchain::add_block(block& target_block)
{
    m_block_chain.push_back(target_block);
}

block& blockchain::get_block(uint_fast64_t index)
{
    auto current_pointer = m_block_chain.begin();
    for(auto i = 0; i < index && current_pointer != m_block_chain.end() ; i++ , current_pointer++);

    if(current_pointer != m_block_chain.end())
    {
        return *current_pointer;
    }
    else
    {
        throw std::exception();
    }
}

bool blockchain::is_valid()
{
    //skipping block 0 (genesis block)
    for (uint_fast64_t i = 1; i < blockchain::size(); ++i)
    {
        block& current_block = blockchain::get_block(i);
        block& previous_block = blockchain::get_block(i - 1);

        if(current_block.m_hash != current_block.calculate_hash())
        {
            return false;
        }
        else if(previous_block.m_hash != current_block.m_previous_block->m_hash)
        {
            return false;
        }
    }
    return true;
}

block& blockchain::get_last()
{
    return m_block_chain.back();
}

block& blockchain::get_genesis()
{
    return m_block_chain.front();
}

uint_fast64_t blockchain::size()
{
    return m_block_chain.size();
}
