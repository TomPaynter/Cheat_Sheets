This is a script to convert a float to a string in a situation where you dont have access to sprintf for whatever reason.

The script is defined by:
```c
uint8_t float_to_string(uint8_t *output, float value, uint8_t dp)
```

It takes the output string, the float value to print, the number of decimal places to print and it returns the total length of the final string.

Example:

```c
        output = my_float_to_string(TempString, 123.777, 1);
```

Source:

```c
uint16_t cheeky_pow(uint16_t base, uint8_t power) {
	uint8_t i;
	uint16_t result = base;

	if (power == 0) {
		return 1;
	}

	for (i=0; i<(power - 1); i++) {
		result = result * base;
	}

	return result;
}


uint8_t float_to_string(uint8_t *output, float value, uint8_t dp)
{
	uint8_t pos = 0,
			digits = 1,
			i=0,
			current_digit;

	if (value < 0) {
		output[0] = (int) "-";
		pos = 1;

		value = value * -1;
	}

	while(value > cheeky_pow(10, digits)){
		digits = digits + 1;
	}

	while(digits > 0) {
		current_digit = (int) value / cheeky_pow(10, (digits - 1));
		output[pos] = '0' + current_digit;
		value = value - current_digit * cheeky_pow(10, (digits - 1));
		digits = digits - 1;
		pos = pos + 1;
	}

	if (dp <= 0) {

		if ((value > 0.5) && (output[pos-1] == '9')) {
					output[pos-2] = output[pos-2] + 1;
					output[pos-1] = '0';
				}

		else if (value > 0.5) {
			output[pos-1] = output[pos-1] + 1;
		}

		return pos + 1;
	}

	else {
		output[pos] = '.';
		pos = pos + 1;

		digits = dp;

		value = value * pow(10, dp);

		while(digits > 0) {
			current_digit = (int) value / cheeky_pow(10, (digits - 1));
			output[pos] = '0' + current_digit;
			value = value - current_digit * cheeky_pow(10, (digits - 1));
			digits = digits - 1;
			pos = pos + 1;
		}

		if ((value > 0.5) && (output[pos-1] == '9')) {
			output[pos-2] = output[pos-2] + 1;
			output[pos-1] = '0';
		}

		else if (value > 0.5) {
			output[pos-1] = output[pos-1] + 1;
		}

	}

return pos + 1;
}
```
