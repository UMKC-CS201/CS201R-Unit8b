#include "Functions.h"

int readFile(vector<Person>& people) {

    ifstream inFile;
    inFile.open("people.txt");
    if (!inFile.is_open()) {
        cout << "File is not open" << endl;
        return 1;
    }

    //SET TEMPORARY VARIABLES FOR INPUTTING PERSON INFORMATION
    int tempAge;
    float tempGPA;
    string inRec, tempStr;
    vector <string> row;

    //LOOP THROUGH THE INPUT FILE
    while (getline(inFile, inRec)) {
        //CHANGE THE INPUT RECORD inRec TO BECOME STRING STREAM inSS
        //THIS WILL ALLOW US TO USE THE RECORD inRec AS THOUGH IT IS
        //AN INPUT STREAM (USEFUL WHEN INPUT IS NOT FIXED)
        stringstream inSS(inRec);
        row.clear();
        // loop through string stream, partioning on ','
        // push each string onto the row vector
        while (getline(inSS, tempStr, ',')) {
            row.push_back(tempStr);
        }

        // if no error in prior conversion, create a person object 
        // calling constructor with lastname row[1], firstname row[2] and age
        // push the object onto the stack
        try {
            if (row[0] == "P") {
                Person tempPerson(row[1], row[2], stoi(row[3]));
                people.push_back(tempPerson);
            }
            //test to create a student & push onto the students vector
            else if (row[0] == "S") {

            }
        }
        catch (invalid_argument error) {
            cout << "RECORD: " << inRec << " HAS AN ERROR: "
                << error.what() << endl;
        }
        catch (...) {
            cout << "RECORD: " << inRec << " IS IN ERROR\n";
        }
    }

    // close the input file
    inFile.close();
    return 0;
}

void printVector(vector<Person> people) {
    cout << "TYPE" << setw(11) << "LAST NAME"
        << setw(17) << "FIRST NAME" << setw(8) << "AGE"
        << setw(18) << "OTHER INFO" << setw(38) << "PETS" << endl;

    for (int i = 0; i < people.size(); i++) {
        people.at(i).print();
    }
    cout << "Total Persons: " << Person::totalPerson << endl << endl;

}

//ADD:  printVector for student vector & student total
