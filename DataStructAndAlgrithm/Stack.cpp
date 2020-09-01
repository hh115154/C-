#include "Stack.h"
#include<stack>
#include<iostream>
using namespace std;
void Stack::DailayTemperater(int arr[], int len)
{
    int* dist = new int[len];
    stack<int> stack;
    for (int i = len -1; i >=0; i--)
    {
        while (!stack.empty() && arr[i] >= arr[stack.top()]) 
            stack.pop();
        
        if (stack.empty())          
            dist[i] = 0;    
        else
            dist[i] = stack.top() - i;

        stack.push(i);
    }

    for (size_t i = 0; i < len; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}

void Stack::AsteroidCrash(int arr[], int len)
{
    stack<int> stack,s;
    bool bPush = false;
    for (int i = 0; i < len; i++)
    {
        bPush = true;
        while(!stack.empty()&&stack.top()>0 && arr[i] < 0){
            if (stack.top()> - arr[i])
            {
                bPush = false;
                break;
            }
            else if (stack.top() < -arr[i])
            {
                stack.pop();
                bPush = true;
            }
            else {
                stack.pop();
                bPush = false;
                break;
            }
        }

        if (bPush) stack.push(arr[i]);
    }

    if (stack.empty())
    {
        cout << "no asteroid left £¡" << endl;
    }
    else {
        while (!stack.empty()) {
            s.push(stack.top());
            stack.pop();
        }

        for (int i = s.size(); i > 0; i--)
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

}
