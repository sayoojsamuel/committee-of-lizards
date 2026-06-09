class MinStack {
   private:
    vector<int> stack;
    vector<int> shadow_stack;

   public:
    MinStack() {}

    void push(int val) {
        stack.push_back(val);
        int shadow_top = val;

        if (!shadow_stack.empty()) {
            shadow_top = shadow_stack.back();
        }
        shadow_stack.push_back(min(val, shadow_top));
    }

    void pop() {
        stack.pop_back();
        shadow_stack.pop_back();
    }

    int top() { return stack.back(); }

    int getMin() { return shadow_stack.back(); }
};
