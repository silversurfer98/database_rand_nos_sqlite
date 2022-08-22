#include<rand.h>
#include<iostream>
#include<sqlite.h>
template <typename t>
void print(const char* a, t x)
{
	std::cout << "\n the " << a << " : " << x << "\n\n";
}

int main()
{
    float* ans = driver();
    for(int i=0;i<100;i++)
    {
        std::cout<<ans[i]<<"\n";
    }
    if(store(ans,1000))
        std::cout<<"jechita maara";
    return 0;
}