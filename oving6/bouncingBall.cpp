#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "bouncingBall.h"

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800}; 
constexpr int BOUNCE_WINDOW_HEIGHT{500};

Config::Config() {
    colorMap.insert({1, Color::blue});
    colorMap.insert({2, Color::red});
    colorMap.insert({3, Color::green});
    colorMap.insert({4, Color::magenta});
}

istream& operator>>(istream& is, Config& cfg) {
    is >> cfg.colorUp;
    is >> cfg.colorDown;
    is >> cfg.velocity;
    return is;
}

void bouncingBall() {
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y, 
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT, "Bouncing ball"};
    
    const int radius{30};
    int alpha{-1};
    int velocity{2};
    Color colour_up{Color::blue};
    Color colour_down{Color::blue};
    double x{0.0};
    double y{360.0};
    double increment_x{0.0};
    double increment_y{0.0};
    int count_bounce_top{0};
    int count_bounce_bottom{0};
    int count_num_passes{0};

    // read from configuration file
    Config slow; 
    Config fast; 
    std::filesystem::path config_file{"konfigurasjon.txt"};
    ifstream inputStream{config_file};
    if (inputStream.is_open()) {
        string line1;
        getline(inputStream, line1);
        istringstream iss1{line1};
        iss1 >> slow;
        string line2;
        getline(inputStream, line2);
        istringstream iss2{line2};
        iss2 >> fast;
    } else {
        cout << "Kunne ikke åpne filen" << endl;
    }

    cout << "slow: " << slow.velocity << " " << slow.colorUp << " " << slow.colorDown << endl;
    
    velocity = slow.velocity;

    cout << "velocity: " << velocity << endl;

    // initialise the run
   
    Color color = slow.colorMap.at(slow.colorUp); 
    Config currentConfig = slow;
    

    while (!window.should_close()) {
        window.draw_circle({static_cast<int>(x), static_cast<int>(y)}, radius, color);
        // determine increments based on the velocity
        cout << "alpha: " << alpha << endl;
        cout << "cos_alpha" << cos(alpha) << endl;
        cout << "sin_alpha" << sin(alpha) << endl;

        increment_x = velocity * cos(alpha);
        increment_y = velocity * sin(alpha);

        cout << velocity * cos(alpha) << endl;

        cout << "increment_x: " << increment_x << endl;
        cout << "increment_y: " << increment_y << endl;

        // movement i x-direction
        if ((increment_x + x) > window.width()) {
            // reached right side - wrap around to the leftmost
            x = 0;
            // increment counter which counts number of full left-to-right passes
            count_num_passes++;
            // alternate between slow and fast configuration every fifth pass
            if (count_num_passes % 5 == 0) {
                // change configuration
                // update both velcity and colors
                if (currentConfig.velocity == slow.velocity) {
                    currentConfig = fast;
                    color = currentConfig.colorMap.at(currentConfig.colorUp);
                    velocity = currentConfig.velocity;

                } else {
                    currentConfig = slow;
                    color = currentConfig.colorMap.at(currentConfig.colorUp);
                    velocity = currentConfig.velocity;
                    
                }
            cout << "velocity: " << velocity << endl;
            }
        } else {
            // moving rightwards
            x += increment_x;
            cout << "x: " << x << endl;
        }

        // movement i y-direction
        if (((count_bounce_top + count_bounce_bottom) % 2) == 0) {
            // move upwards
            color = currentConfig.colorMap.at(currentConfig.colorUp);
            if ((increment_y + y) < 0) {
                // reached top
                count_bounce_top++;
                alpha = -alpha;
            } else {
                // move upwards
                y += increment_y;
                cout << "y: " << y << endl;
            }
        } else {
            color = currentConfig.colorMap.at(currentConfig.colorDown);
            // move downwards
            if ((increment_y + y) > window.height()) {
                // reached bottom
                count_bounce_bottom++;
                alpha = -alpha;
            } else {
                // move downwards
                y += increment_y;
                cout << "y: " << y << endl;
            }
        }
        window.next_frame();
        
        
    }
}
