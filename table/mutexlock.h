//
// Created by lg on 2022/4/20.
//

#ifndef SSTABLE_BUILDER_TABLE_MUTEXLOCK_H_
#define SSTABLE_BUILDER_TABLE_MUTEXLOCK_H_

#include <mutex>
class Mutex {
 public:
  Mutex() = default;
  ~Mutex() = default;

  Mutex(const Mutex&) = delete;
  Mutex& operator=(const Mutex&) = delete;

  void Lock() { mu_.lock(); }
  void Unlock() { mu_.unlock(); }
  void AssertHeld() {}

 private:
  friend class CondVar;
  std::mutex mu_;
};

class MutexLock {
    public:
    explicit MutexLock(Mutex* mu) : mu_(mu) {
      this->mu_->Lock();
    }
    ~MutexLock() { this->mu_->Unlock(); }

    MutexLock(const MutexLock&) = delete;
    MutexLock& operator=(const MutexLock&) = delete;

    private:
    Mutex* const mu_;
};

#endif //SSTABLE_BUILDER_TABLE_MUTEXLOCK_H_
