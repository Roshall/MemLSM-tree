cmake_minimum_required(VERSION 3.21)
project(sstable_builder)

set(CMAKE_CXX_STANDARD 17)

add_executable(sstable_builder "" table/mutexlock.cc table/mutexlock.h)
target_sources(sstable_builder PRIVATE
    main.cpp
    table/block.cc
    table/block_builder.cc
    table/coding.cc
    table/crc32c.cc
    table/filter_block.cc
    table/format.cc
    table/hash.cc
    table/iterator.cc
    table/merger.cc
    table/table.cc
    table/table_builder.cc
    table/two_level_iterator.cc
    table/cache.cc
    table/comparator.cc
    table/status.cc
    table/options.cc
)
