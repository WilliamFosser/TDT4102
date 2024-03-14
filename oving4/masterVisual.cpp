#include "masterVisual.h"
#include "utilities.h"
#include "std_lib_facilities.h"
#include "mastermind.h"

void addGuess(MastermindWindow &mwin, const string code, const char startLetter)
{
	Guess newGuess{code, startLetter};
	mwin.guesses.push_back(newGuess);
}

void addFeedback(MastermindWindow &mwin, const int correctPosition, const int correctCharacter)
{
	Feedback newFeedback{correctPosition, correctCharacter};
	mwin.feedbacks.push_back(newFeedback);
}

void MastermindWindow::drawCodeHider()
{
	if (code_hidden) {
		draw_rectangle(Point{padX, 3 * padY}, winW - size * padX, padY, Color::black);
	}
}

MastermindWindow::MastermindWindow(int x, int y, int w, int h, int size, const string &title) 
: AnimationWindow(x, y, w, h, title),
guessBtn{{upperLeftCornerBtn.x, upperLeftCornerBtn.y}, btnW, btnH, "Add"},
guess{{upperLeftCornerInBox.x, upperLeftCornerInBox.y}, inBoxW, inBoxH, ""},
size(size)
{
	add(guess);
	add(guessBtn);
	guessBtn.setCallback(std::bind(&MastermindWindow::cb_guess, this));
};

void MastermindWindow::drawGuessesAndFeedbacks()
{
	std::map<int, Color> colorConverter{
		{1, Color::red},
		{2, Color::green},
		{3, Color::yellow},
		{4, Color::blue},
		{5, Color::blue_violet},
		{6, Color::dark_cyan}};

	for (int guessIndex = 0; guessIndex < static_cast<int>(guesses.size()); guessIndex++)
	{
		// Implementer funksjonalitet slik at det vises fargede rektangler i grafikkvinduet
		// Tegn gjettet som ligger på plassen guessIndex i vektoren guesses.
		for (int i = 0; i < size; i++)
		{
			// Tegn rektangler ved bruk av draw_rectangle(). Bruk: colorConverter.at() for å få riktig farge
			Point rectangleRightCorner;
			rectangleRightCorner.x = padX;
			rectangleRightCorner.y = 3 * padY + 2 * guessIndex * padY;

			int colorIndex = static_cast<int>(guesses.at(guessIndex).code.at(i));
			draw_rectangle(rectangleRightCorner, padX, padY, colorConverter.at(colorIndex), Color::black);
			rectangleRightCorner.x += 2 * padX; // Move to the next position for the next character
			}
		}

	for (int feedbackIndex = 0; feedbackIndex < static_cast<int>(feedbacks.size()); feedbackIndex++)
	{
		
		// Implementer funksjonalitet slik at det vises sirkler i grafikkvinduet
		
		
		for (int i = 0; i < size; i++)
		{
			// Tegn sirkler ved hjelp av draw_circle().
			Point circleCenter;
			circleCenter.x = padX + size * padX + 2 * padX;
			circleCenter.y = 3 * padY + 2 * feedbackIndex * padY + padY / 2;

			int correctPosition = feedbacks.at(feedbackIndex).correctPosition;
			int correctCharacter = feedbacks.at(feedbackIndex).correctCharacter;

			for (int j = 0; j < correctPosition; j++)
			{
				draw_circle(circleCenter, padY / 4, Color::black, Color::black);
				circleCenter.x += padX / 2;
			}

			for (int k = 0; k < correctCharacter; k++)
			{
				draw_circle(circleCenter, padY / 4, Color::white, Color::black);
				circleCenter.x += padX / 2;
			}
		}
	}
}

string MastermindWindow::wait_for_guess()
{

	while (!button_pressed && !should_close())
	{
		drawGuessesAndFeedbacks();
		// Burde tegnes sist siden den skal ligge på toppen
		drawCodeHider();

		next_frame();
	}
	button_pressed = false;

	string newGuess = guess.getText();
	guess.setText("");

	return newGuess;
}

string MastermindWindow::getInput(unsigned int n, char lower, char upper)
{
	bool validInput = false;
	string guess;
	while (!validInput && !should_close())
	{
		guess.clear();
		string input = wait_for_guess();
		if (input.size() == n)
		{
			for (unsigned int i = 0; i < n; i++)
			{
				char ch = input.at(i);
				if (isalpha(ch) && toupper(ch) <= upper && lower <= toupper(ch))
				{
					guess += toupper(ch);
				}
				else
					break;
			}
		}
		if (guess.size() == n)
		{
			validInput = true;
		}
		else
		{
			cout << "Invalid input guess again" << endl;
		}
	}
	return guess;
}

void MastermindWindow::setCodeHidden(bool hidden) {
	code_hidden = hidden;
}

void playMastermindVisual() {
	constexpr int stringSize = 4; 
    constexpr int letterCount = 6; 
    // Bruker constexpr for at konstantene skal evalueres ved kompileringstid, og dermed optimalisere koden.
    // Hvis brukeren kunne valgt i starten av spillet ville const vært hensiktsmessig. 
	const char startLetter = 'A';
    string code = randomizeString(stringSize, startLetter, startLetter + (letterCount-1));
    string guess; 
    int maxGuesses = 6;

    int rightCharAndPosition = 0;
    int i = 0;
	MastermindWindow mwin{900, 20, winW, winH, stringSize, "Mastermind"};
	mwin.setCodeHidden(false);
	
    
	do {
		cout << "Gjett en kode med " << stringSize << 
				" bokstaver. Bokstavene skal være i intervallet A - " 
				<< char('A' + letterCount - 1) << endl;
		guess = mwin.getInput(stringSize, startLetter, startLetter + (letterCount-1)); 
		addGuess(mwin, guess, startLetter);
		rightCharAndPosition = checkCharactersAndPosition(code, guess);
		int rightChar = checkCharacters(code, guess);
		mwin.drawGuessesAndFeedbacks();
		cout << "\nAntall riktige bokstaver på riktig plass: " << rightCharAndPosition << endl;
		cout << "Antall riktige bokstaver: " << rightChar << endl;
		cout << "Antall forsøk igjen: " << maxGuesses - i - 1 << endl << endl;
		i++;
	} while (rightCharAndPosition < stringSize && i < maxGuesses);
    if (rightCharAndPosition == stringSize) {
        cout << "Gratulerer! Du klarte det!" << endl;

    } else {
        cout << "Beklager, du tapte. Trykk 6 for å starte igjen" << code << endl;
    }
		mwin.wait_for_close();
}
