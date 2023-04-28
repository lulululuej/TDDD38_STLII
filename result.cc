#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <iterator>
#include <sstream>
#include <iomanip>

using namespace std;

/* Expected output:

Highscore      | Fastest       
Team D  : 37   | Team C
Team C  : 12   | Team B
Team B  : 5    | Team A

*/

string team_to_string(pair<string, int> const& team)
{
    ostringstream oss{};
    oss << left << setw(8) << team.first
        << ": " << setw(4) << team.second;
    return oss.str();
}

int main()
{
    vector<pair<string, int>> const results {
        {"Team C", 12},
        {"Team B", 5},
        {"Team A", 0},
        {"Team D", 37},
    };

    vector<pair<string, int>> highscore(3);
    
    // write your code here
    auto print = [](std::pair<string, int> const& pair){ std::cout << pair.second << ' '; };
    auto compareSecondValue = [](pair<string, int> const& lhs, pair<string, int> const& rhs){ return lhs.second > rhs.second; };

    std::for_each(results.begin(), results.end(), print); // 12 5 0 37
    std::cout << '\n';

    std::partial_sort_copy(results.begin(), results.end(), highscore.begin(), highscore.end(), compareSecondValue); // sorted results will write into highscore;
    std::for_each(highscore.begin(), highscore.end(), print); // 37 12 5
    std::cout << '\n';

    std::cout << std::left << std::setw(14) << "Highscore"  << " | " << setw(14) << "Fastest" << std:: endl;

    // what transform for?
    std::transform(highscore.begin(), highscore.end(), results.begin(), ostream_iterator<string>{cout, "\n"},
        [](pair<string, int> const& a, pair<string, int> const& b)
        {
            return team_to_string(a) + " | " + b.first;
        }
    );
}
