#include<bits/stdc++.h>

using namespace std;

#include <iostream>
#include <stack>


    // Helper function to insert an element into its correct sorted position
    void sortedInsert(std::stack<int>& st, int element) {
        // Base case: If stack is empty OR the top element is smaller than our element,
        // we can safely push our element to the top.
        if (st.empty() || st.top() < element) {
            st.push(element);
            return;
        }

        // If the top element is greater, pop it out and hold it in the call stack
        int topElement = st.top();
        st.pop();

        // Recursively find the correct spot for our element
        sortedInsert(st, element);

        // Put the held element back on top
        st.push(topElement);
    }


    // Main function to sort the stack
    void sortStack(std::stack<int>& st) {
        // Base case: An empty stack or a stack with 1 element is already sorted
        if (st.empty()) {
            return;
        }

        // Pop the top element and hold it in the recursion call stack frame
        int topElement = st.top();
        st.pop();

        // Recursively sort the remaining elements in the stack
        sortStack(st);

        // Insert the held topElement back into the now-sorted stack
        sortedInsert(st, topElement);
    }




int main(){
stack<int> st ;
    st.push(11);
    st.push(2);
    st.push(32);
    st.push(3);
    st.push(41);

    sortStack(st);

    while(!st.empty()){
        cout << st.top() <<endl;
        st.pop();
    }

    return 0;
}