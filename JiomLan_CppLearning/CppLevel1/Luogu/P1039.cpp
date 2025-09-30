#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

int person_count, liar_count, statement_count;
int guilty_person = -1;
int person_truth_status[105];
string person_names[105];
pair<int, string> statements[105];
string weekdays[] = {
    "Today is Monday.",
    "Today is Tuesday.",
    "Today is Wednesday.",
    "Today is Thursday.",
    "Today is Friday.",
    "Today is Saturday.",
    "Today is Sunday."
};

int getPersonId(string name) {
    for (int i = 0; i < person_count; i++) {
        if (person_names[i] == name) {
            return i;
        }
    }
    return -1;
}

int judgeStatement(int day, int guilty_id, int speaker_id, string statement) {
    if (statement == "I am guilty.") {
        return guilty_id != speaker_id;
    }
    if (statement == "I am not guilty.") {
        return guilty_id == speaker_id;
    }
    for (int i = 0; i < person_count; i++) {
        if (person_names[i] + " is guilty." == statement) {
            return i != guilty_id;
        }
    }
    for (int i = 0; i < person_count; i++) {
        if (person_names[i] + " is not guilty." == statement) {
            return i == guilty_id;
        }
    }
    for (int i = 0; i < 7; i++) {
        if (weekdays[i] == statement) {
            return day != i;
        }
    }
    return -1;
}

bool checkAssumption(int day, int suspect_id) {
    memset(person_truth_status, -1, sizeof(person_truth_status));
    
    for (int i = 0; i < statement_count; i++) {
        pair<int, string> current_statement = statements[i];
        int truth_value = judgeStatement(day, suspect_id, current_statement.first, current_statement.second);
        int speaker_id = current_statement.first;
        
        if (truth_value == 0) {
            if (person_truth_status[speaker_id] == -1) {
                person_truth_status[speaker_id] = 0;
            } else if (person_truth_status[speaker_id] == 1) {
                return false;
            }
        } else if (truth_value == 1) {
            if (person_truth_status[speaker_id] == -1) {
                person_truth_status[speaker_id] = 1;
            } else if (person_truth_status[speaker_id] == 0) {
                return false;
            }
        }
    }
    
    int confirmed_liars = 0;
    int unknown_status = 0;
    for (int i = 0; i < person_count; i++) {
        if (person_truth_status[i] == 1) confirmed_liars++;
        else if (person_truth_status[i] == -1) unknown_status++;
    }
    
    return confirmed_liars <= liar_count && confirmed_liars + unknown_status >= liar_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> person_count >> liar_count >> statement_count;
    for (int i = 0; i < person_count; i++) {
        cin >> person_names[i];
    }
    
    for (int i = 0; i < statement_count; i++) {
        string speaker_name, statement_content;
        cin >> speaker_name;
        speaker_name.erase(speaker_name.end() - 1);
        getline(cin, statement_content);
        statement_content.erase(statement_content.end() - 1);
        statement_content.erase(statement_content.begin());
        statements[i] = make_pair(getPersonId(speaker_name), statement_content);
    }
    
    int valid_count;
    for (int day = 0; day < 7; day++) {
        valid_count = 0;
        for (int i = 0; i < person_count; i++) {
            if (checkAssumption(day, i)) {
                valid_count++;
                guilty_person = i;
            }
        }
        if (valid_count > 1) {
            cout << "Cannot Determine";
            return 0;
        }
    }
    
    if (guilty_person == -1) {
        cout << "Impossible";
    } else {
        cout << person_names[guilty_person];
    }
    
    return 0;
}
