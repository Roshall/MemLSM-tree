#include <iostream>
#include <fstream>

#include "table/options.h"
#include "table/table.h"

leveldb_hot::Status TestReadSSTable(const std::string& file_name) {
  std::ifstream file(file_name, std::ios_base::binary);
  if (!file) {
    return leveldb_hot::Status::IOError("can't open file");
  }
  leveldb_hot::Table* table{};
  auto s = leveldb_hot::Table::Open(leveldb_hot::Options(), &file, &table);
  if (!s.ok()) {
    delete table;
    return s;
  }
  leveldb_hot::ReadOptions ro;
  ro.fill_cache = false;
  leveldb_hot::Iterator* iter = table->NewIterator(ro);
  std::string r;
  for (iter->SeekToFirst(); iter->Valid(); iter->Next()) {
    r.clear();
  }
  s = iter->status();
  if (!s.ok()) {
    return s;
  }

  delete iter;
  delete table;
  return leveldb_hot::Status::OK();
}

int main() {
  auto s = TestReadSSTable("/home/lg/lsm/experiment/ex/010778.ldb");
  if (s.ok()) {
    std::cout << "pass\n";
  } else {
    std::cout << "fail\n";
    std::cerr << s.ToString() << '\n';
  }
  return 0;
}
