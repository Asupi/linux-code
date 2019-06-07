#include<iostream>
#include<unistd.h>
#include<vector>
#include<stdio.h>

#if 0
pthread_mutex_t lock;
pthread_cond_t cond;

//实现一个生产者消费者模型
//首先得有一个交易场所
std::vector<int>data;

//然后得有两个角色（生产者和消费者）两个线程

void* Product(void* arg)
{
    (void)arg;
    //负责把交易数据放进去
    int count=0;
    while(1)
    {
        pthread_mutex_lock(&lock);
        data.push_back(++count);
        pthread_mutex_unlock(&lock);
        pthread_cond_signal(&cond);
        usleep(789789);
    }
    return NULL;
}

void* Consume(void* arg)
{
    (void)arg;
    //负责把交易场所中的数据取出来
    while(1)
    {
        //每次取最后一个元素
        pthread_mutex_lock(&lock);
        //这个代码最好写成while而不是if
        //pthread_cond_wait返回值不一定就是其他线程signal
        //这个函数也可能被信号打断
        if(data.empty())
        {
            //1.先释放锁
            //2.等待条件就绪（有其他线程调用 pthread_cond_signal
            //3.如果条件就绪了，重新获取锁
            //1和2必须是原子的
            //加上wait的意义在于如果没有数据，消费者线程不必进行空转，节省了资源
            pthread_cond_wait(&cond,&lock);
        }
            int result =data.back();
            data.pop_back();
            printf("result = %d\n", result);
        
            pthread_mutex_unlock(&lock);
            usleep(123123);
    }
    return NULL;
}

int main()
{
    pthread_cond_init(&cond,NULL);
    pthread_mutex_init(&lock,NULL);
    
    


    pthread_t tid1,tid2,tid3,tid4,tid5,tid6;
    pthread_create(&tid1,NULL,Product,NULL);
    pthread_create(&tid3,NULL,Product,NULL);
    pthread_create(&tid5,NULL,Product,NULL);
    pthread_create(&tid2,NULL,Consume,NULL);
    pthread_create(&tid4,NULL,Consume,NULL);
    pthread_create(&tid6,NULL,Consume,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);
    pthread_join(tid3,NULL);
    pthread_join(tid4,NULL);
    pthread_join(tid5,NULL);
    pthread_join(tid6,NULL);


    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&lock);
    return 0;
}
#endif



//使用队列来表示生产者和消费者模型
//同步与互斥不一定非得用互斥锁和条件变量来实现
//使用信号量来完成‘
//信号量就是一个计数器，表示可用资源的个数
//P 申请资源，计数器-1
//V 申请操作，计数器+1
//当计数器为0 的时候，再去P操作就会发生阻塞
#if 0
#include"blockingqueue.hpp"

BlockingQueue<int> queue(100);
void* Product(void* arg)
{
    (void)arg;
    int count=0;
    while(1)
    {
        queue.Push(++count);
        usleep(789789);
    }
    return NULL;
}

void* Consume(void* arg)
{
    (void)arg;
    while(1)
    {
    int count=0;
    queue.Pop(&count);
    printf("count= %d\n",count);
    usleep(123123);
    }
    return NULL;
}


int main()
{
    pthread_t tid1,tid2;
    pthread_create(&tid1,NULL,Product,NULL);
    pthread_create(&tid2,NULL,Consume,NULL);

    pthread_join(tid1,NULL);
    pthread_join(tid2,NULL);

    return 0;
}
#endif

#if 1
#include"threadpool.hpp"

//这个类由用户自己控制
//需要依赖那些数据可以随意添加和修改
class MyTask:public Task{
public:
    MyTask(int id): id_(id)
    {
    }
    ~MyTask()
    {}
    void Run()
    {
        //执行用户自定制的逻辑
        printf("id=%d\n",id_);
    }
private:
    int id_;
};
int main()
{
    ThreadPool pool(10);
    for(int i=0;i<20;++i)
    {
    pool.AddTask(new MyTask(i));
    }
    while(1){
        sleep(1);
    }
    return 0;
}
#endif
