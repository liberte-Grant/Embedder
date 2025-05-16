#ifndef BUTTON_H
#define BUTTON_H

#include <stdbool.h>
#include <zephyr/drivers/gpio.h>

enum class ButtonPolarity {
  NORMAL,
  INVERTED
};

class Button {

public:
  Button(const struct gpio_dt_spec *gpio);
  ~Button();

  bool isPressed(ButtonPolarity polarity = ButtonPolarity::NORMAL);

private:
  const struct gpio_dt_spec *gpio;

};

#endif // BUTTON_H
