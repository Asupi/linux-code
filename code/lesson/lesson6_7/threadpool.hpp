#pragma once  //保证头文件只包含一次
#include<stdio.h>
#include"blockingqueue.hpp"

class Task{
public:
    virtual ~Task()
    {

    }
    virtual void Run()
    {

    printf("base Run\n");

    }
};
//线程池对象启动的时候会创建一组线程
//每个线程都需要完成一定的任务（执行一定的代码逻辑，这个逻辑是由调用者来决定的）
//任务是一段代码，可以用函数来表示
class ThreadPool
{
public:
    //n 表示创建线程的数量
    ThreadPool(int n):queue_(100),worker_count_(n){
        //创建出若干个线程
        
        for(int i=0;i<worker_count_;++i)
        {
            pthread_t tid;

            pthread_create(&tid,NULL,ThreadEntry,this);
            workers_.push_back(tid);
        }
        
    }
    ~ThreadPool()
    {
        //让线程退出，然后再回收
        for(size_t i=0;i<workers_.size();++i)
        {
            pthread_cancel(workers_[i]);

        }
         for(size_t i=0;i<workers_.size();++i)
       
        {
            pthread_join(workers_[i],NULL);
        }
    }

    //使用线程池 的时候就需要调用者加入一些任务让线程池去执行
    void AddTask(Task*task)
    {
        queue_.Push(task);
    }
private:
    BlockingQueue<Task*> queue_;
    int worker_count_;
    std::vector<pthread_t> workers_;

    static void* ThreadEntry(void* arg)
    {
        ThreadPool* pool=(ThreadPool*)arg;
        while(true)
        {
            //循环尝试从阻塞队列中获取任务
            //获取一个任务就执行一个任务
            Task* task=NULL;
            pool->queue_.Pop(&task);
            //task表面看是一个Task*类型，实际上指向Mytask*
            task->Run();
            delete task;
        }
    }
};
