/*
	* Given a range[a,b] and a value we need to add to k all the numbers whose indices are in the range from [a,b].

	*We can do an O(1) update by adding k to index a and add -k to index (b + 1)
	*Doing this kind of update, ith number in the array will be prefix sum of array from index 1 to i because we are adding k 
	*to the value at index a and subtracting k from the value at index b + 1 and taking prefix sum will give us the actual value for each index after m operations.
	*So, we can do all m updates in O(m) time. Now we have to check the largest number in the original array. i.e. the index i such that prefix sum attains the maximum value.
	*We can calculate all prefix sums as well as maximum prefix sum in O(n) time which will execute in time.
*/

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);



// Complete the arrayManipulation function below.
long arrayManipulation(int n, vector<vector<int>> queries) {
    	
	vector <pair<int, int>> v;
	for(auto query : queries){
	//storing the query
        //this will add k in the prefix sum for index >= a
        	v.push_back(make_pair(query[0], query[2]));
        
        //adding -1*k will remove k from the prefix sum for index > b 
        	v.push_back(make_pair(query[1] + 1, -1 * query[2]));
	}
	
	long mx = 0, sum = 0;
	int m = queries.size();
    
    	sort(v.begin(), v.end());
    
    	for(int i=0 ; i<2*m; i++) {
    
        	sum += v[i].second;
        	mx = max(mx, sum);
        }
	return mx;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nm_temp;
    getline(cin, nm_temp);

    vector<string> nm = split_string(nm_temp);

    int n = stoi(nm[0]);

    int m = stoi(nm[1]);

    vector<vector<int>> queries(m);
    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long result = arrayManipulation(n, queries);

    fout << result << "\n";

    cout << result << endl;

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

