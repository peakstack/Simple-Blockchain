#include <iostream>
#include "block.h"
#include "blockchain.h"

void mine_blocks(int times);

blockchain block_chain = blockchain();

int main()
{
    Keccak keccak;
    block genesis_block = block(block_chain.size());
    genesis_block.m_hash = keccak("0");
    genesis_block.m_previous_block = &genesis_block;
    genesis_block.mine(block_chain.m_difficulty);
    block_chain.add_block(genesis_block);

    mine_blocks(200);

    std::cout << "blockchain is " << (block_chain.is_valid() ? "valid" : "not valid") << std::endl;
}

void mine_blocks(int times)
{
    for (int i = 0; i < times; ++i) {
        auto *current_block = new block(block_chain.size());
        current_block->m_previous_block = &block_chain.get_last();
        current_block->update();
        current_block->mine(block_chain.m_difficulty);
        block_chain.add_block(*current_block);

        if(i % 20 == 0)
        {
            std::cout << "new difficulty: " << ++block_chain.m_difficulty << std::endl;
        }

    }
}
