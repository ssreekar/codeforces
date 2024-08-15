#include <stack>
#include <utility>

// Minimum Stack
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