#ifndef BLOCKCHAIN_BLOCKCHAIN_H
#define BLOCKCHAIN_BLOCKCHAIN_H


#include <list>
#include "block.h"

class blockchain {

public:
    uint_fast64_t m_difficulty = 1;
    void add_block(block& target_block);
    block& get_block(uint_fast64_t index);
    block& get_last();
    bool is_valid();
    block& get_genesis();
    uint_fast64_t size();

private:
    std::list<block> m_block_chain = std::list<block>();
};


#endif
