#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix {
  public:
    explicit Matrix(vector<vector<char>> arr): array(arr) {};
    vector<char>& operator[](size_t index) {
      if (index >= array.size()) {
        throw out_of_range("out of range");
      }

      return array[index];
    };
    const vector<char>& operator[](size_t index) const {
      if (index >= array.size()) {
        throw out_of_range("out of range");
      }

      return array[index];
    };

    vector<string> relativeWords(size_t row, size_t col) {
      vector<string> words {};
      if (!array.size() || row >= array.size() || col >= array[row].size()) return words;
      string last_s(1, array[row][col]);
      words.push_back(last_s);
      vector<vector<int>> symbol {
        {0, 1},
        {0, -1},
        {-1, 0},
        {1, 0},
        {1, 1},
        {-1, -1},
        {-1, 1},
        {1, -1}
      };

      for_each(symbol.cbegin(), symbol.cend(), [col, row, &words, &last_s, this](vector<int> s) {
        for (int i = row + s[0], j = col + s[1]; i >= 0 && i < array.size() && j >= 0 && j < array[i].size(); i += s[0], j += s[1]) {
          words.push_back(last_s + array[i][j]);
          last_s = *--words.end();
        }
        last_s = string(1, array[row][col]);
      });

      return words;
    };

    size_t length() {
      return array.size();
    }
  private:
    vector<vector<char>> array;
};

int main() {
  Matrix m({
    {'t', 'h', 'i', 's'},
    {'w', 'a', 't', 's'},
    {'o', 'a', 'h', 'g'},
    {'f', 'g', 'd', 't'}
  });
  vector<string> wordsTable {"this", "two", "fat", "that"};

  cout<<"find words:"<<endl;
  for (size_t i = 0; i < m.length(); i++) {
    for (size_t j = 0; j < m[i].size(); j++) {
      auto words = m.relativeWords(i, j);

      for_each(words.cbegin(), words.cend(), [&wordsTable](string word) {
        if (find(wordsTable.cbegin(), wordsTable.cend(), word) != wordsTable.cend()) {
          cout<<word<<endl;
        }
      });
    }
  }

  return 0;
}
