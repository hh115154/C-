#include "Stack.h"
#include<stack>
#include<iostream>
#include<algorithm>
#include<deque>
#include<unordered_map>
#include<map>
using namespace std;
void Stack::DailayTemperater(int arr[], int len)
{
    int* dist = new int[len]();
    stack<int> stack;

    for (int i = 0; i < len; i++)
    {
        while (!stack.empty() && arr[stack.top()] < arr[i]) {
            dist[stack.top()] = i - stack.top();
            stack.pop();
        }

        stack.push(i);
    }

    //show res
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


    //show res
    if (stack.empty())
    {
        cout << "no asteroid left " << endl;
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
            if (st.empty()) break;//break保证找到从左至右第一个极大元素,避免计算左侧上升斜坡

            //底边长为凹陷部分的长度，当前位置与栈顶位置差为n(n>=2),则n-1为底边长
            int x = i - st.top() - 1;
            //矩形最高点为栈顶和当前位置取小的一个，如果栈顶与topIdx位置高度相同(y=0,不改变面积)，继续弹栈，直到遇见更高的
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

bool Stack::isStrValid(const string& str)
{
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if ('(' == str[i] || '[' == str[i] || '{' == str[i])
            st.push(str[i]);
        else {
            if (st.empty())
                return false;
            char top = st.top();
            switch (top)
            {
            case '(':
                if (')' == str[i])
                    st.pop();
                else
                    return false;
                break;
            case'[':
                if (']' == str[i])
                    st.pop();
                else
                    return false;
                break;
            case'{':
                if ('}' == str[i])
                    st.pop();
                else
                    return false;
                break;
            default:
                return false;
            }
        }
    }

    return st.empty();
}

vector<int> Stack::nextGreaterNum(vector<int> subset, vector<int> arr)
{
    vector<int> res;
    unordered_map<int, int> mp;
    stack<int> smallTopStk;
    for (int i = 0; i < arr.size(); i++)
    {
        while(!smallTopStk.empty()&& smallTopStk.top()<arr[i]){
                mp[smallTopStk.top()] = arr[i];
                smallTopStk.pop();
        }
        smallTopStk.push(arr[i]);         
    }
    for (int i = 0; i < subset.size(); i++)
        res.push_back(mp.count(subset[i])?mp[subset[i]]:-1);
    return res;
}

vector<int> Stack::nextGreaterNum2(vector<int> arr)
{
    int size = arr.size();
    vector<int>res1(size, -1);
    stack<int>st;
    for (int i = 0; i < size*2; i++)
    {
        int idx = i % size;       
        while (!st.empty() && arr[st.top()] < arr[idx]) {
            res1[st.top()] = arr[idx];
            st.pop();
        }
        if (i < size)
            st.push(i);//idx
    }
    return res1;
}

string Stack::decodeString(const string& str)
{
    string res("");
    string subRes("");
    string tmpStr(subRes);
    stack<int> stNums;
    int num1 = 0;
    int num = 0;
    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case '[':
            stNums.push(num);
            subRes = "";            
            num = 0;
            break;
        case']':           
            if (!stNums.empty()) {
                num1 = stNums.top(); 
                stNums.pop();
            }
            tmpStr=subRes==""?res:subRes;
            for (int i = 1; i < num1; i++)
                subRes += tmpStr;
            res += subRes;
            subRes = "";
            
            break;
        default:
            if (str[i] >= '0' && str[i] <= '9')
                num = 10 * num + str[i] - '0';
            else//letters
                subRes += str[i];
            break;
        }
    }

    return res;





    //stack<char> st;
    //
    //for (int i = 0; i < str.length(); i++)
    //{
    //    if (']' != str[i]) {
    //        st.push(str[i]);
    //    }
    //    else {
    //        while ('[' != st.top()&&!st.empty()) {
    //            subRes = st.top() + subRes;
    //            st.pop();
    //        }
    //        if(!st.empty())
    //            st.pop();
    //        while (!st.empty()&& '[' != st.top()) {
    //            num = numLen * (st.top() - '0')+num;
    //            numLen *= 10;
    //            st.pop(); 
    //        }
    //        string tmp = subRes==""?res:subRes;
    //        for (int i = 1; i < num; i++)
    //            subRes += tmp;
    //        res += subRes;
    //    }
    //    num = 0;
    //    numLen = 1;
    //    subRes = "";
    //}
    //return res;
}

bool isStrtLog(const string& str) {
    return str.find("start")!=string::npos;
}
int getFuncId(const string& str) {
    int pos = str.find(":");
    int id = 0;
    for (int i = 0; i < pos; i++)
        id = 10 * id + str[i] - '0';
    return id;
}
int getTimeStmp(const string& str) {
    int pos = str.find(":");
    pos = str.find(":", pos+1);
    int time = 0;
    for (int i = pos+1; i < str.length(); i++)
        time = 10 * time + str[i] - '0';
    
    return time;
}

vector<int> Stack::exclusiveTime(int n, vector<string>& logs)
{
    //递归的话，累加每次执行的时间，因此输出数组长度就是n
    vector<int>res(n, 0);
    stack<int> stIdx;
    int preTime = 0;
    for (int i = 0; i < logs.size(); i++)
    {
        int idx = getFuncId(logs[i]);
        bool isStrt = isStrtLog(logs[i]);
        int time = getTimeStmp(logs[i]);
        if (!stIdx.empty())
            res[stIdx.top()] += time - preTime;
        preTime = time;
        if (isStrt)
            stIdx.push(idx);
        else {
            res[stIdx.top()]++;
            preTime++;
            stIdx.pop();
        }
    }

    return res;
}

int Stack::largestRectangleArea(vector<int>& height)
{
    return 0;
}
