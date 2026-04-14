#include <indicators/progress_bar.hpp>
#include <thread>
#include <chrono>
#include <indicators/cursor_control.hpp>
#include <indicators/progress_bar.hpp>


int progress_barr1() {
  using namespace indicators;
  ProgressBar bar{
    option::BarWidth{50},
    option::Start{"["},
    option::Fill{"="},
    option::Lead{">"},
    option::Remainder{" "},
    option::End{"]"},
    option::PostfixText{"Extracting Archive"},
    option::ForegroundColor{Color::green},
    option::ShowPercentage{true},
    option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}
  };
  
  // Update bar state
  while (true) {
    bar.tick();
    if (bar.is_completed())
      break;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  return 0;
}

int progress_barr2() {
  using namespace indicators;

  // Hide cursor
  show_console_cursor(false);

  ProgressBar bar{
    option::BarWidth{50},
    option::Start{"["},
    option::Fill{"■"},
    option::Lead{"■"},
    option::Remainder{"-"},
    option::End{" ]"},
    option::PostfixText{"Loading dependency 1/4"},
    option::ForegroundColor{Color::cyan},
    option::ShowPercentage{true},
    option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}  };

  // Update bar state
  bar.set_progress(10); // 10% done

  // do some work
  std::this_thread::sleep_for(std::chrono::milliseconds(800));

  bar.set_option(option::PostfixText{"Loading dependency 2/4"});  

  bar.set_progress(30); // 30% done

  // do some more work
  std::this_thread::sleep_for(std::chrono::milliseconds(700));

  bar.set_option(option::PostfixText{"Loading dependency 3/4"});  

  bar.set_progress(65); // 65% done

  // do final bit of work
  std::this_thread::sleep_for(std::chrono::milliseconds(900));

  bar.set_option(option::PostfixText{"Loaded dependencies!"});

  bar.set_progress(100); // all done

  // Show cursor
  show_console_cursor(true);

  return 0;
}

int progress_barr3() {
  using namespace indicators;

  // Hide cursor
  show_console_cursor(false);

  indicators::ProgressBar bar{
    option::BarWidth{50},
    option::Start{" ["},
    option::Fill{"█"},
    option::Lead{"█"},
    option::Remainder{"-"},
    option::End{"]"},
    option::PrefixText{"Training Gaze Network 👀"},
    option::ForegroundColor{Color::yellow},
    option::ShowPercentage{true},
    option::ShowElapsedTime{true},
    option::ShowRemainingTime{true},
    option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}
  };

  // Update bar state
  while (true) {
    bar.tick();
    if (bar.is_completed())
      break;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }

  // Show cursor
  show_console_cursor(true);

  return 0;
}

int main() {
  // Run the first progress bar example
  progress_barr1();

  // Run the second progress bar example
  progress_barr2();

  // Run the third progress bar example
  progress_barr3();

  return 0;
}