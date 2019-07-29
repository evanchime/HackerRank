#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    using name_value = map<string,string>;
        map<string,name_value>tag_map;
        string root_tag, tag, tag_name, attr_name, value, queries;
        string::size_type pos0, pos1, pos2, pos3, pos4, pos5;
        int N, Q, inner_flag{}, root_flag{};

        cin >> N >> Q;
        cin.ignore(numeric_limits<std::streamsize>::max(),'\n');

        // the search pattern
        for(int i = 0; i < N; ++i){
                getline(cin, tag);
                // get tag name
                if(tag[1] == '/'){ 
			pos0 = tag.find(">");
			if(root_tag == tag.substr(2, pos0 - 2))
				root_flag ^= 1;
			else
				inner_flag ^= 1;
			continue;
		}
                pos1 = tag.find_first_of("\x20>");
		if(!root_flag){
			root_tag = tag_name = tag.substr(1, pos1 - 1);
			root_flag ^= 1;
		}else if(inner_tag){
			pos5 = tag_name.find_first_of(".");
			tag_name = tag_name.substr(0, pos5 + 1) + tag.substr(1, pos1 - 1);
			inner_tag ^= 1;
		}else{
			tag_name += ("." + tag.substr(1, pos1 - 1));
		}
                //search pattern
                while((pos2 = tag.find("\"", pos1)) != string::npos){
                        pos1 += 1;
                        pos3 = tag.find(" ", pos1);
                        attr_name = tag.substr(pos1, pos3 - pos1);
                        pos2 += 1;
                        pos4 = tag.find("\"", pos2);
                        value = tag.substr(pos2, pos4 - pos2);
                        pos1 = pos4 + 1;
                        tag_map[tag_name][attr_name] = value;
                }
        }


        for (int i = 0; i < Q; ++i){
                getline(cin, tag);
                /*pos1 = tag.find_last_of(".");
                if(pos1 == string::npos)
                        pos1 = 0;
                else
                        pos1 += 1;*/
                //pos2 = tag.find("~", pos1);
		pos1 = tag.find("~");
                //tag_name = tag.substr(pos1, pos2 - pos1);
                tag_name = tag.substr(0, pos1);
		attr_name = tag.substr(pos1 + 1);
                auto temp = tag_map[tag_name][attr_name];
                queries += ((temp.empty() ? "Not Found!" : temp) + "\n");
        }

        cout << queries << endl;
	/*string x = "<tag1>";
	auto pos = x.find_first_of("  >");
	cout << pos << endl;*/

  
    return 0;

