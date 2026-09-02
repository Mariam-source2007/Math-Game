#include <iostream>
#include <ctime>
#include <string>
using namespace std;

// We will make enum that represents the operator and the question level
enum EnOperator { Plus=1, Minus=2, Multiply=3, Divide=4, MixOperator=5};

// We will make enum that represents the question level
enum EnQuestionLevel { Easy=1, Medium=2, Hard=3, MixLevel=4};

// We will make struct that represents the scores
struct StScores
{
	int TimesRightAnswers;
	int TimeswrongAnswers;
};

// We will make struct that represents the test and it will contain the operator and the question level and numbers to be used in the question
struct StPrepareTest
{
	EnOperator Operator;
	EnQuestionLevel QuestionLevel;
	int FirstNumber;
	int SecondNumber;
};

// First We will get from user the number of question they want to be asked
int GetQuestionNumber()
{
	int QuestionNumbers;
	cout<<"How many questions do you want to answer? ";
	cin>>QuestionNumbers;
	return QuestionNumbers;
}
// Second We will get from user the question level they want to be asked in
EnQuestionLevel GetQuestionLevel()
{
	int QuestionLevel;
	cout << "Enter the question level (1=Easy, 2=Medium, 3=Hard, 4=Mix): ";
	cin >> QuestionLevel;
	return (EnQuestionLevel)QuestionLevel;
}

// Third We will get from user the operator they want to practice numbers with
EnOperator GetOperator()
{
	int Operator;
	cout << "Enter the operator (1=Plus, 2=Minus, 3=Multiply, 4=Divide, 5=Mix): ";
	cin >> Operator;
	return (EnOperator)Operator;
}

// Fourth we will generate random numbers to prpare the test and From and To will depends on the question level
int GenerateRandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}

// These two functions will generate random operator and question level based on the From and To values and convert them immediately to the enum type
EnOperator GenerateRandomOperator(int From, int To)
{
	return (EnOperator)(rand() % (To - From + 1) + From);
}
EnQuestionLevel GenerateRandomLevel(int From, int To)
{
	return (EnQuestionLevel)(rand() % (To - From + 1) + From);
}

// Fifth we will prepare the test we will implwmwnt two switches based on the operator and the question level and we will return the struct that contains the operator and the question level

StPrepareTest GetTestReady(EnOperator Operator, EnQuestionLevel QuestionLevel)
{
	StPrepareTest Test;
	// First switch that assign the Test.operartor 
	switch (Operator)
	{
	case EnOperator::Plus:
		Test.Operator = EnOperator::Plus;
		break;
	case EnOperator::Minus:
	{
		Test.Operator = EnOperator::Minus;
		break;
	}
	case EnOperator::Multiply:
	{
		Test.Operator = EnOperator::Multiply;
		break;
	}
	case EnOperator::Divide:
	{
		Test.Operator = EnOperator::Divide;
		break;
	}

	// in this case we need to call the GenerateRandomOperator function to generate a random operator between 1 and 4 and assign it to the Test.Operator
	case EnOperator::MixOperator:
	{
		Test.Operator = GenerateRandomOperator(1, 4);
		break;
	}
	}
	//  Second switch that assign the Test.QuestionLevel
	switch (QuestionLevel)
	{
	case EnQuestionLevel::Easy:
	{
		Test.QuestionLevel = EnQuestionLevel::Easy;
		Test.FirstNumber = GenerateRandomNumber(1, 10);
		Test.SecondNumber = GenerateRandomNumber(1, 10);
		break;
	}
	case EnQuestionLevel::Medium:
	{
		Test.QuestionLevel = EnQuestionLevel::Medium;
		Test.FirstNumber = GenerateRandomNumber(10, 100);
		Test.SecondNumber = GenerateRandomNumber(10, 100);
		break;
	}
	case EnQuestionLevel::Hard:
	{
		Test.QuestionLevel = EnQuestionLevel::Hard;
		Test.FirstNumber = GenerateRandomNumber(100, 1000);
		Test.SecondNumber = GenerateRandomNumber(100, 1000);
		break;
	}

	// As in first switch in this case we need to call the GenerateRandomLevel function to generate a random level between 1 and 3 and assign it to the Test.QuestionLevel
	case EnQuestionLevel::MixLevel:
	{
		Test.QuestionLevel = GenerateRandomLevel(1, 3);

		// to determine the From and The To values we will use another switch based on the Test.QuestionLevel

		switch (Test.QuestionLevel)
		{
		case EnQuestionLevel::Easy:
		{
			Test.FirstNumber = GenerateRandomNumber(1, 10);
			Test.SecondNumber = GenerateRandomNumber(1, 10);
			break;
		}
		case EnQuestionLevel::Medium:
		{
			Test.FirstNumber = GenerateRandomNumber(10, 100);
			Test.SecondNumber = GenerateRandomNumber(10, 100);
			break;
		}
		case EnQuestionLevel::Hard:
		{
			Test.FirstNumber = GenerateRandomNumber(100, 1000);
			Test.SecondNumber = GenerateRandomNumber(100, 1000);
			break;
		}
		}
		break;
	}
	}
	// Finally we have prepared the test so now return the struct and that is why we have nade the test in struct to be able to return it form a fn in one time
	return Test;
}
// cast the test.operator to a char to be able to show it to the user in the question and we will use a switch to do that

char GetOperatorChar(EnOperator Operator)
{
	switch (Operator)
	{
	case EnOperator::Plus:
		return '+';
	case EnOperator::Minus:
		return '-';
	case EnOperator::Multiply:
		return '*';
	case EnOperator::Divide:
		return '/';
	}
	return ' ';
}
string GetQuestionLevelString(EnQuestionLevel QuestionLevel)
{
	switch (QuestionLevel)
	{
	case EnQuestionLevel::Easy:
		return "Easy";
	case EnQuestionLevel::Medium:
		return "Medium";
	case EnQuestionLevel::Hard:
		return "Hard";
	case EnQuestionLevel::MixLevel:
		return "Mix";
	}
	return "";
}
string GetOperatorToString(EnOperator Operator)
{
	switch (Operator)
	{
	case EnOperator::Multiply:
	{
		return "Multiply";
		break;
	}
	case EnOperator::Divide:
	{
		return "Divide";
		break;
	}
	case EnOperator::Plus:
	{
		return "Plus";
		break;
	}
	case EnOperator::Minus:
	{
		return "Minus";
		break;
	}
	case EnOperator::MixOperator:
	{
		return "Mix";
		break;
	}
	}
	return "";
}
// After we have prepared the test we will show the question to the user and get their answer in a function

int ShowTestAndGetAnswer(StPrepareTest Test)
{
	int UserAnswer;
	EnOperator Operator = Test.Operator;
	cout << Test.FirstNumber << endl;
	cout << Test.SecondNumber << ' ' << GetOperatorChar(Operator) << endl;
	cout << "_____________\n\n" << endl;
	cout << "Tell what is your answer to check it " << endl;
	cin >> UserAnswer;
	return UserAnswer;
}
// Calculate the correct answer

int CalcCorrectAnswer(StPrepareTest Test)
{
	int CorrectAnswer;

	switch (Test.Operator)
	{
	case EnOperator::Plus:
	{
		CorrectAnswer = Test.FirstNumber + Test.SecondNumber;
		break;
	}
	case EnOperator::Minus:
	{
		CorrectAnswer = Test.FirstNumber - Test.SecondNumber;
		break;
	}
	case EnOperator::Multiply:
	{
		CorrectAnswer = Test.FirstNumber * Test.SecondNumber;
		break;
	}
	case EnOperator::Divide:
	{
		CorrectAnswer = Test.FirstNumber / Test.SecondNumber;
		break;
	}
	}
	return CorrectAnswer;
}
// Compare the user answer with the correct answer and return true if they are equal and false if not

bool CorrectOrNot(int UserAnswer, int CorrectAnswer)
{
	bool IsAnswerCorrect = (UserAnswer == CorrectAnswer);
	return IsAnswerCorrect;
}
void ShowResults(bool IsAnswerCorrect, int CorrectAnswer)
{
	if (IsAnswerCorrect)
	{
		cout << "\aRight Answer :-)\n\n" << endl;
		system("Color 2F");
	}
	else
	{
		cout << "\aWrong Answer :-(\n\n" << endl;
		cout << "The correct answer is: " << CorrectAnswer << endl;
		system("Color 4F");
	}
}
void UpdateScores(StScores &Scores, bool IsAnswerCorrect)
{
	if (IsAnswerCorrect)
	{
		Scores.TimesRightAnswers++;
	}
	else
	{
		Scores.TimeswrongAnswers++;
	}
}
bool AskUserToContinue()
{
	char UserChoice;
	cout << "Do you want to continue? (Y/N): ";
	cin >> UserChoice;
	return (UserChoice == 'Y' || UserChoice == 'y');
}
// End The raound and show to the user all data about the round like how many times he guess it right....

void EndRound(int QuestionNumbers, EnQuestionLevel QuestionLevel, EnOperator Operator, StScores Scores)
{
	if (Scores.TimesRightAnswers > Scores.TimeswrongAnswers)
	{
		cout << "___________________________________________\n\n" << endl;
		cout << "Final Result is Passed :-)" << endl<<endl;
		cout << "___________________________________________\n\n" << endl;
	}
	else
	{
		cout << "Final Result is Failed :-(" << endl;
	}
	cout << "Total Questions: " << QuestionNumbers << endl;
	cout << "Question Level: " << GetQuestionLevelString(QuestionLevel) << endl;
	cout << "Operator: " << GetOperatorToString(Operator) << endl;
	cout << "Times Right Answers: " << Scores.TimesRightAnswers << endl;
	cout << "Times Wrong Answers : " << Scores.TimeswrongAnswers << endl;
	cout << "___________________________________________\n\n" << endl;
}
//All-in-All fn here we start aour game using all previous fns
void StartMathGame()
{
	StScores Scores = { 0, 0 };
	int QuestionNumbers = GetQuestionNumber();
	EnQuestionLevel QuestionLevel = GetQuestionLevel();
	EnOperator Operator = GetOperator();
	StPrepareTest Test;
	for (int Q = 1; Q <= QuestionNumbers; Q++)
	{
		cout << "\n\n";
		cout << "Question [" << Q << "]\n\n";
		Test = GetTestReady(Operator, QuestionLevel);
		int UserAnswer = ShowTestAndGetAnswer(Test);
		int CorrectAnswer = CalcCorrectAnswer(Test);
		bool IsAnswerCorrect = CorrectOrNot(UserAnswer, CorrectAnswer);
		ShowResults(IsAnswerCorrect, CorrectAnswer);
		UpdateScores(Scores, IsAnswerCorrect);
	}
	EndRound(QuestionNumbers,QuestionLevel,Operator, Scores);
}
int main()
{

	srand((unsigned)time(NULL));
	do {
		system("Color 0F");
		system("cls");
		StartMathGame();
	} while (AskUserToContinue());
}