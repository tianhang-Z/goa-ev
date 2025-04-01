#pragma once

#include <atomic>
#include <condition_variable>
#include <queue>
#include <thread>

#include "Callbacks.hpp"
#include "noncopyable.hpp"

namespace goa {

namespace ev {

/*
线程池 含有一组线程和一个任务队列    线程会从队列自动取任务执行
队列未满时 可以向队列中添加任务 runTask()
队列有任务时 可以从队列中取出任务 take()
*/
class ThreadPool : noncopyable {
 public:
  explicit ThreadPool(size_t threadNum, size_t maxQueueSize = 65536,
                      const ThreadInitCallback& callback = nullptr);
  ~ThreadPool();

  void runTask(const Task&);
  void runTask(Task&&);
  void stop();
  size_t threadNum() const;

 private:
  //每个线程执行的函数 其会从任务队列中取出任务
  void runInThread(size_t index);
  Task take();

  using ThreadPtr = std::unique_ptr<std::thread>;
  using ThreadList = std::vector<ThreadPtr>;

  ThreadList threads_;
  std::mutex mutex_;
  std::condition_variable notEmpty_;
  std::condition_variable notFull_;
  std::queue<Task> taskQueue_;
  const size_t maxQueueSize_;
  std::atomic_bool running_;
  ThreadInitCallback threadInitCallback_;
};

}  // namespace ev

}  // namespace goa
