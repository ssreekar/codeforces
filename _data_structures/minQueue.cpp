#include <stack>
#include <utility>

// Minimum Stack
// Don't call min when stack is empty
template <class T>
struct minStack {
    stack<pair<T, T> > st;
    
    void push(T element) {
        T newMin = st.empty() ? element : std::min(element, st.top().second);
        st.push({element, newMin});
    }

    void pop() {
        st.pop();
    }

    T top() {
        return st.top().first;
    }

    T min() {
        if (st.empty()) {
            cerr << "Min Stack Empty" << endl;
        }
        return st.top().second;
    }

    bool empty () {
        return st.empty();
    }

    size_t size() {
        return st.size();
    }

    void clear() {
        st.clear();
    }
};


// Minimum Queue
template <class T>
struct minQueue {
    minStack<T> addStack;
    minStack<T> removeStack;

    private: 
    void flipStacks() {
        if (removeStack.empty()) {
            while(!addStack.empty()) {
                T topElement = addStack.top();
                addStack.pop();
                removeStack.push(topElement);
            }
        }
    }

    public: 
    void push(T element) {
        addStack.push(element);
    }


    void pop() {
        flipStacks();
        if (!removeStack.empty()) {
            return removeStack.pop();
        }
    }

    T front() {
        flipStacks();
        if (!removeStack.empty()) {
            return removeStack.top();
        }
    }
    
    T min() {
        if (addStack.empty() && removeStack.empty()) {
            cerr << "Min Queue Empty" << endl;
        } else if (removeStack.empty()) {
            return addStack.min();
        } else if (addStack.empty()) {
            return removeStack.min();
        }
        return std::min(addStack.min(), removeStack.min());
    }

    bool empty() {
        return (addStack.empty() && removeStack.empty());
    }

    size_t size() {
        return addStack.size() + removeStack.size();
    }

    void clear() {
        addStack.clear();
        removeStack.clear();
    }
};
