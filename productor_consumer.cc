#include"../leetcode/common.h"
#define LENGTH 20

struct Itempool
  {
	int write_flag;
	int read_flag;
	vector<int> vect;
	
	pthread_mutex_t mutex;
	pthread_cond_t consume;
	pthread_cond_t produce;
};  
int  Consume(Itempool* consum)
{ 
	int value;
	pthread_mutex_lock(&consum->mutex);
	//if(consum->read_flag==consum->write_flag)
	while(consum->read_flag==consum->write_flag)
	{
		cout<<"---no items to consume,having to waitting---"<<endl;
		pthread_cond_wait(&consum->produce,&consum->mutex);

 	 }
	value=consum->vect[consum->read_flag];
	consum->read_flag++;
	if(consum->read_flag>=LENGTH)
		consum->read_flag=0;
	pthread_cond_signal(&consum->consume);
	pthread_mutex_unlock(&consum->mutex);
	return value;
}
void Produce(Itempool* produce,int value)
{ 
	pthread_mutex_lock(&produce->mutex);
	//if((produce->write_flag+1)%LENGTH==produce->read_flag)
	while((produce->write_flag+1)%LENGTH==produce->read_flag)
 	{
		cout<<"---full item to wait  consume---"<<endl;
		pthread_cond_wait(&produce->consume,&produce->mutex);
	}
	produce->vect[produce->write_flag]=value;
	produce->write_flag++;
	if(produce->write_flag==LENGTH)
	{
		produce->write_flag=0;
 	} 
	//有数据呢？？？
	pthread_cond_signal(&produce->produce);
	pthread_mutex_unlock(&produce->mutex);
}
void* Consume_Ex(void* item)
{
	Itempool* tmp=(Itempool*)item;
	static int cnt=1;
	while(1)
	{
	//	sleep(1);
		int result=Consume(tmp);
		cout<<"消费者消费第"<<cnt<<"个产品为："<<result<<endl;
		if(++cnt==10000)
		{
			cout<<"完成计划总数:"<<cnt<<endl;
			break;
		}
	}
}
void* Produce_Ex(void* item)
{
	Itempool* tmp=(Itempool*)item;
	for(int i=1;i<=10000;i++)
	{
		cout<<"生产者生产第"<<i<<"个产品为"<<i<<endl;
		Produce(tmp,i);
	}
}

int main()
{ 
	pthread_t td1;
	pthread_t td2;
	int ret=0;

	Itempool reposity;
	reposity.write_flag=0;
	reposity.read_flag=0;
	reposity.mutex=PTHREAD_MUTEX_INITIALIZER;
	reposity.consume=PTHREAD_COND_INITIALIZER;
	reposity.produce=PTHREAD_COND_INITIALIZER;
	reposity.vect.resize(LENGTH,0);

	ret=pthread_create(&td2,NULL,Consume_Ex,&reposity);
	if(ret==-1)
	{
		cout<<"创建线程2失败"<<endl;
	}
	ret=pthread_create(&td1,NULL,Produce_Ex,&reposity);
	if(ret==-1)
	{
		cout<<"创建线程1失败"<<endl;
	}
	pthread_join(td1,NULL);
	pthread_join(td2,NULL);
	return 0;
}
