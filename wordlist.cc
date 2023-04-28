#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <string>

using namespace std;
int main() {
    cout << "Enter the wordlist : ";
    vector<string> text { istream_iterator<string>{cin}, istream_iterator<string>{} };
    vector<string> words {text};

    for_each(words.begin(), words.end(), [](string &n){ cout << n << ' '; });
    cout << "\n";
    sort(begin(words), end(words));
    for_each(words.begin(), words.end(), [](string &n){ cout << n << ' '; });
    cout << "\n";
    words.erase(unique(begin(words), end(words)), end(words));
    for_each(words.begin(), words.end(), [](string &n){ cout << n << ' '; });
    cout << "\n";

    // the diff of capture caluse and parameter in lambda expression 
    /*
        capture clause is for lambda to capture the value provide outside the transform
        parameter is the data provided by transform list
    */
    std::transform(words.begin(), words.end(), ostream_iterator<string>{cout, "\n"},
    [&text](string const& word)
    {
        int n = count(text.begin(), text.end(), word ) ;
        return word + ": " + to_string(n);
    }
    );

    /* transform (1)
    template<class InputIt, class OutputIt, class UnaryOperation>
    OutputIt transform(InputIt first1, InputIt last1,
                    OutputIt d_first, UnaryOperation unary_op)
    {
        while (first1 != last1)
            *d_first++ = unary_op(*first1++);
    
        return d_first;
    }
    */
    /* transfrom (2)
    template<class InputIt1, class InputIt2, class OutputIt, class BinaryOperation>
    OutputIt transform(InputIt1 first1, InputIt1 last1,
                    InputIt2 first2, OutputIt d_first,
                    BinaryOperation binary_op)
    {
        while (first1 != last1)
            *d_first++ = binary_op(*first1++, *first2++);
    
        return d_first;
    }
    */

    /*vector<string> text { istream_iterator<string>{cin},
                          istream_iterator<string>{} };
    vector<string> words {text};
    
    sort(begin(words), end(words));
    words.erase(unique(begin(words), end(words)), end(words));
 
    transform(begin(words), end(words), ostream_iterator<string>{cout, "\n"},
              [&text](string const& word)
              {
                  int n = count(begin(text), end(text), word);
                  return word + ": " + to_string(n);
              });*/
}