#include "Stack.h"
#include<stack>
#include<iostream>
#include<algorithm>
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
        cout << "no asteroid left ��" << endl;
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

int Stack::getrain(vector<int> arr){
    int res = 0;
    //1，下一元素如果比栈顶元素大，则开始计算雨量，雨量与横坐标差相关
    //2，下一元素比栈顶小，则入栈
    int i = 0;
    stack<int> st;
    int topIdx = 0;
    while(i<arr.size()){
        while(!st.empty()&&arr[i]>arr[st.top()]){
            topIdx = st.top();
            st.pop();
            if (st.empty()) break;//以上三行保证找到第一个极大元素

            //底边长为凹陷部分的长度，当前位置与栈顶位置差为n(n>=2),则n-1为底边长
            int x = i - st.top() - 1;
            //1,高为栈顶和当前位置取小的一个，如果栈顶与topIdx位置高度相同(y=0,不改变面积)，继续弹栈，直到遇见更高的
            int y = min(arr[i],arr[st.top()]) - arr[topIdx];
            res+= x*y;
        }
        st.push(i++);
    }
    
    return res;
}

void Stack::removeDuplicates(string& str){

    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if(st.empty())
            st.push(str[i]);
        else{
            if(st.top()==str[i])
                st.pop();
            else
                st.push(str[i]);
        }
    }
    stack<char> st1;
    while(!st.empty()){
        st1.push(st.top());
        st.pop();
    }
    string str1;
    while(!st1.empty()){
        str1.push_back(st1.top());
        st1.pop();
    }
    str = str1;

}