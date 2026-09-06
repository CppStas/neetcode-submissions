class MinStack {
public:
    MinStack() {}

    void push(int val) {
        if (data_.empty() || val < min_) min_ = val;
        data_.push_back(val);
    }

    void pop() {
        data_.pop_back();
        if (!data_.empty()) {
            min_ = *min_element(data_.begin(), data_.end());
        }
    }

    int top() {
        return data_.back();
    }

    int getMin() {
        if (data_.empty()) return data_.back();
        return min_;
    }
private:
    deque<int> data_;
    int min_{};
};