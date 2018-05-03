#include"../leetcode/common.h"
//大于零要确定变量是否为有符号数
void* my_memmove(void* dst,const void* src,ssize_t count)
{
	if(dst==NULL||src==NULL||count<=0)
		return NULL;
	//为常量字符串
	const char* data=(const char*)src;
	char* tmp=(char*)dst;
	if(data<tmp)
	{
		while((--count)>=0)
		{
			tmp[count]=data[count];
		}
	}else
	{
		for(int i=0;i<count;i++)
		{
			tmp[i]=data[i];
		}
	}
	return tmp;
}
//copy
void* memmove_blog(void* dest, const void* src, size_t n)
{
    char*     d  = (char*) dest;
    const char*  s = (const char*) src;
  
    if (s>d)
    {
         // start at beginning of s
         while (n--)
            *d++ = *s++;
    }
    else if (s<d)
    {
        // start at end of s
        d = d+n-1;
        s = s+n-1;
  
        while (n--)
           *d-- = *s--;
    }
    return dest;
}
int main()
{
	char buf[15]="hellowordhell0";
	my_memmove(buf+5,buf,9);
	//memmove_blog(buf+5,buf,9);
	cout<<buf<<endl;
}
