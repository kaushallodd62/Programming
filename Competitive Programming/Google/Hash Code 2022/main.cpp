#include<bits/stdc++.h>
using namespace std;

typedef struct project {
    vector<pair<string, int> > skills;
    int no_days;
    int score_awarded;
    int best_before;
    int no_roles;
}project;

typedef struct contributor {
    vector<pair<string, int> > skills;
    int next_available_day;
}contributor;

typedef struct sk_cr {
    vector<pair<string, int> > contributors;
}sk_cr;

bool compare (const pair<string, project>& a, const pair<string, project>& b) {
    return a.second.best_before >= b.second.best_before;
}

bool cmp (const pair<string, int>& a, const pair<string, int>& b) {
    return a.second >= b.second;
}

void sort_map(unordered_map<string, project>& M) {

    vector<pair<string, project> > A;
    for (auto& it : M) {
        A.push_back(it);
    }
    M.erase(M.begin(), M.end());
 
    // Sort using comparator function
    sort(A.begin(), A.end(), compare);
  
    // Print the sorted value
    for (auto& it : A) {
        M[it.first] = it.second;
    }
}

int main() {
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    //INPUT
    int c, p;
    fin >> c >> p;
    unordered_map<string, contributor> contributors;
    unordered_map<string, project> projects;
    unordered_map<string, sk_cr> skill_map;
    
    while(c--) {
        string name;
        fin >> name;
        int n; fin >> n;
        while(n--) {
            string skill;
            fin >> skill;
            int level;
            fin >> level;
            contributors[name].skills.push_back({skill, level});
            contributors[name].next_available_day = 0;
        }
    }
    while(p--) {
        string name;
        fin >> name;
        project p;
        fin >> p.no_days;
        fin >> p.score_awarded;
        fin >> p.best_before;
        fin >> p.no_roles;
        int temp = p.no_roles;
        while(temp--) {
            string skill;
            fin >> skill;
            int level;
            fin >> level;
            p.skills.push_back({skill, level});
        }
        projects[name] = p;
    }


    //LOGIC
    //sort_map(projects);
    for(auto& contributor: contributors) {
        for(auto& skill: contributor.second.skills) {
            skill_map[skill.first].contributors.push_back({contributor.first, skill.second});
        }
    }
    map<string, vector<string> > ans;
    for(auto& project: projects) {
        vector<string> temp;
        for(auto& skill: project.second.skills) {
            bool found = false;
            for(auto& contributor: skill_map[skill.first].contributors) {
                if((contributor.second >= skill.second) && contributors[contributor.first].next_available_day == 0) {
                    contributors[contributor.first].next_available_day = 1;
                    found = true;
                    temp.push_back(contributor.first);
                    break;
                }
            }
            if(found == false) {
                temp.erase(temp.begin(), temp.end());
                break;
            }
        }
        if(temp.size()!=0) 
            ans.insert({project.first, temp});
        
    }

     //OUTPUT
    fout << ans.size() << endl;
    for(auto& project: ans) {
        fout << project.first << endl;
        for(auto& contributor: project.second) {
            fout << contributor << " ";
        }
        fout << endl;
    }

    //
    // fout << c << " " << p << endl;
    // for(auto &x: contributors) {
    //     fout << x.first << endl;
    //     for (auto &y: x.second) {
    //         fout << y.first << " " << y.second << endl;
    //     }
    // }

    // for(auto &x: projects) {
    //     fout << x.first << " " << x.second.no_days << " " << x.second.score_awarded << " " << x.second.best_before << " " << x.second.no_roles << endl;
    //     for(auto &y: x.second.skills) {
    //         fout << y.first << " " << y.second << endl;
    //     }

    // }
    cout << "SUCCESS" << endl;
    return 0;
}