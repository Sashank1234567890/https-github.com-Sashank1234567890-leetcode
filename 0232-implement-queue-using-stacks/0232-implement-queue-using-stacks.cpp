class MyQueue {
public:

    stack<int> input;
    stack<int> output;
    int peekEl = -1;

    MyQueue() {
    }

    void push(int x) {

        if(input.empty() && output.empty())
            peekEl = x;

        input.push(x);
    }

    int pop() {

        if(output.empty()) {

            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        int val = output.top();
        output.pop();

        if(!output.empty())
            peekEl = output.top();

        return val;
    }

    int peek() {

        if(output.empty()) {

            while(!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};