#include <stdio.h>
#include <gpiod.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]) {
    const char *chipname = "gpiochip0";
    unsigned int line_num = 26; // GPIO par défaut
    struct gpiod_chip *chip;
    struct gpiod_line *line;
    int value = 0;

    if (argc > 2 && strcmp(argv[1], "--gpio") == 0) {
        line_num = atoi(argv[2]);
    }

    chip = gpiod_chip_open_by_name(chipname);
    if (!chip) {
        perror("Open chip failed");
        return 1;
    }

    line = gpiod_chip_get_line(chip, line_num);
    if (!line) {
        perror("Get line failed");
        gpiod_chip_close(chip);
        return 1;
    }

    if (gpiod_line_request_output(line, "gpio-toggle", 0) < 0) {
        perror("Request line as output failed");
        gpiod_chip_close(chip);
        return 1;
    }

    while (1) {
        gpiod_line_set_value(line, value);
        value = !value;
        sleep(1);
    }

    gpiod_chip_close(chip);
    return 0;
}
