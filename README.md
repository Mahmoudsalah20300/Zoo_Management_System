# Assignment 1 - zOOP

## Introduction

In Assignment 1 (A1) of the OOP1 practicals (KU) you will implement a zoo management tool.

This document describes the structure of the assignment and the expected functionality of the program.

## Learning Goals

- Foundations of classes:
    - attributes, methods
    - constructor, copy constructor, destructor
    - inheritance, virtual functions
- Strings & streams:
    - `std::string`
    - files
- Some data structures of the standard library:
    - e.g. `std::vector`

## Specification

Some general specifications must be followed for every assignment in this course. A list of these specifications can be
found
here: [Assessment of Assignments - Deductions](https://www.notion.so/coding-tugraz/Assessment-of-Assignments-How-do-you-get-your-points-work-in-progress-00d2624846f4491391b389e6a48fa180?pvs=4#0af0c923deff4c4bb8740f5698aca451)

Please follow these specifications to avoid point deductions.

Additionally, the following specifications must be followed for this assignment (A1) as well:

- You **must** implement and use all described classes in your assignment. The required classes are described in detail
  in the [description folder](./description).
- The provided `main.cpp` **must not** be changed and is replaced with the original version in our test system. The
  existing functionalities in `Utils.hpp/cpp` and `CommandLine.hpp/cpp` should not be changed,
  however, you are allowed to extend these classes. They will not be replaced in the test system.

If any of these specifications are not followed, this may result in a deduction of up to -25 % per specification.

In this assignment (but only in this one), you do not have to check if memory was allocated successfully.

## Grading

Assignment 1 is worth **18 points**.

**Attention**: If you pass **less than half of the public test cases for A1** you will be deregistered from the OOP1 
KU without a grade.

Information on how your assignment submission will be assessed can be found
here: [Assessment of Assignments](https://www.notion.so/coding-tugraz/Assessment-of-Assignments-How-do-you-get-your-points-work-in-progress-00d2624846f4491391b389e6a48fa180)

Here you can find an overview of how your total grade for the KU will be
calculated: [Procedure and Grading](https://www.notion.so/coding-tugraz/Practicals-structure-grading-and-plagiarism-work-in-progress-76127221ed43451abc7ffba7852595e3)

There will not be any assignment interviews for A1.

## Submission

- Push to your repository
- The last commit on the main branch before the deadline will be graded
- Deliverables: all .cpp and .hpp files needed to run your program
- **Deadline: 09.04.2025 23:59 (Austrian time)**
- **Assignment 1 is solo work!** See
  our [Guidelines on Plagiarism](https://www.notion.so/coding-tugraz/Practicals-structure-grading-and-plagiarism-work-in-progress-76127221ed43451abc7ffba7852595e3?pvs=4#93a62cfe219949929fa2fc41f2f1ff37)

> **Note:** Please also pay attention to the section on how to use and cite ChatGPT or similar!

## General Notes

The notes given in this section are important for the whole assignment description.

> **Note:** Any changes made to the upstream repository will be announced on our Discord server. Please make sure to
> [join the server](https://discord.gg/uSqkwGs8KS) and then join the OOP1 group in the #roles channel.

- `\n` shouldn't be printed as separate characters, instead it represents the newline character.
- Note the leading and trailing spaces in the text fields! You can make them visible by selecting the text field.
- Words in sharp brackets (like `<ANIMAL_TYPE>`) should be replaced by calculated or given data. They are *not* part of
  the output itself! For a better understanding you can look at the example output at the end of this document.
- The user input is **case-insensitive**. This means that `forest`, `ForEsT` and `FOREST` would all be valid inputs.
- All additional whitespaces (leading, trailing, or additional whitespaces between command and parameters or between two
  parameters) in the input should be ignored.
- The program needs to be able to handle arbitrary input in any form (e.g. strings when integers are expected, input
  of any length).


## Framework

We provide to you a `main.cpp` which must be used as the starting point of your program. This file must not be changed, 
as it will be replaced by the test system with the original version, so your program must be compatible with it.

Additionally, we provide the class Utils (`Utils.hpp/Utils.cpp`), which contains a function to safely convert a string
to an integer and a function to safely convert a string to a float, and the class CommandLine (`CommandLine.hpp/cpp`), 
which should be used to convert user input into Command objects.
The existing functionality should not be changed, but you can extend these classes if needed.


## Custom Data Types / Classes

After reading the Assignment Description below, it is recommended to start with the definition of the custom data types (= classes)
used in this program. Descriptions for all of these classes can be found in the [description folder](./description). In this first step, it is not required to
actually implement any of the described methods in detail, but they should be declared at least. Keep in mind that all data members (member
variables) of all classes should be declared as `private` / `protected`. You are allowed to add further member variables
and methods to all classes.

## Assignment Description

In this assignment you will implement a simple zoo management tool where the user can buy and place different enclosures
on a grid based map and populate the enclosures with various animals bought from a shop.

<details>
<summary><h3>Starting the Program</h3></summary>

The program is called with five command line parameters. The first parameter is the name of the zoo, the second the path
to the shop config file, the third the amount of starting money, the fourth the width of the zoo and the fifth the
height of the zoo.

A valid call is for example:

```
./a1 zOOP shop_config.csv 1000000 9 9
```

If the program is called

- with the wrong number of parameters,
- with a shop config file that cannot be opened or does not start with the correct magic number `OOP\n`,
- with an invalid amount of starting money (must be an integer greater than zero), or
- with an invalid width or height (both must be integers greater or equal to 1 and smaller or equal to 9)

the corresponding error message should be printed and the program should terminate with the correct return
value (see [Return Values and Error Messages](#return-values-and-error-messages)).

<details>
<summary><h4>Parsing the Shop Config File</h4></summary>

The animal shop gets its initial information from the passed config file. Thus, this file should be parsed as follows:

Every config file contains a magic number in the first line (`OOP\n`). This string has to be checked for its
correctness. If the magic number is correct you can assume that the file is correctly formatted and no further checks of
the file's content are needed.

The next line contains the shop's name.

After that, the available animals to buy in the shop, if there are any, will be listed.
Each line represents a single animal and consists of its name, type (`Lion`, `Giraffe`, `Gorilla` or `Dolphin`), age and specific animal trait
separated by the character `;`.

A valid config file of a shop named "shOOP" with two animals (Lion Eisi, age 17 with mane length of 20 cm and Giraffe 
Hans, age 5 with neck height of 2.1 m) would for example look like this:

```
OOP\n
shOOP\n
Eisi;Lion;17;20\n
Hans;Giraffe;5;2.1\n
```

</details>
</details>

<details>
<summary><h3>Welcome Message</h3></summary>

Next, the user should be greeted with the output:

```
\n
Welcome to your Zoo "<ZOO_NAME>"!\n
This zoo has a size of <WIDTH> x <HEIGHT>!\n
```

where

- `<ZOO_NAME>` should be replaced by the name of the zoo,
- `<WIDTH>` should be replaced by the width of the map, and
- `<HEIGHT>` should be replaced by the height of the map.

After the welcome message the map of the zoo should be printed once as described below. Then, the user can start entering commands (see Program Loop).

</details>

<details>
<summary><h3>Map</h3></summary>

The user can build enclosures on their zoo map and buy animals from the shop to add to these enclosures.

Enclosures on the map

- will always be rectangular,
- consist of at least one field, and
- may consist of multiple fields.

Animals on the map will always be displayed on a single field. A field can only display at most one animal and be
part of at most one enclosure.

During runtime, the current map status that has resulted from the user's actions will be
printed multiple times.

The map should always be printed in the following format:

- The map output starts with a single `\n`. If the map output was deactivated, the empty line should also not be 
  printed.
- A singular field will always be printed as three characters. These depend on the enclosure type and the animal
  displayed on the field. The first character specifies the type of the enclosure it is part of:
    - `S` for `Savanna`
    - `F` for `Forest`
    - `A` for `Aquarium`
    - <code>&nbsp;</code> (space) if it is not part of an enclosure

  Animals are not placed directly on the fields but only added to an enclosure in general. They are displayed **left to
  right, top to bottom in the fields of their enclosure**. If there are fewer animals
  than fields in an enclosure, the remaining fields are printed without an animal. There can never be more animals 
  than fields in an enclosure.
  The second and third character may display an animal that has been added to the enclosure:
    - `Li` for `Lion`
    - `Gi` for `Giraffe`
    - `Go` for `Gorilla`
    - `Do` for `Dolphin`
    - <code>&nbsp;&nbsp;</code> (two spaces) if no animal is listed on this field

  Example field in a savanna enclosure listing a lion:

  ```
  SLi
  ```

  Example field in a savanna enclosure without an animal (pay attention to the spaces):

  ```
  S  
  ```

  Example field not in an enclosure (pay attention to the spaces):

  ```
     
  ```
- Each field has a fence post at each of its four corners. Fence posts are printed as `+` and always exist, even
  if there are no fences attached to them.
- The zoo is fenced in all around. A horizontal fence is printed as `---`, a vertical fence is printed as `|`.
- Each separate enclosure is also fenced in, using the same fence prints.
- If two neighboring fields are part of the same enclosure, there is no fence between them. Instead, the field
  prints should be separated by a single space <code>&nbsp;</code> (horizontal neighbors) or by three spaces
  <code>&nbsp;&nbsp;&nbsp;</code>(vertical neighbors).
- The output should also include indexing on the top and left side of the map. Indexing starts with `1`. The height and
  the width of the map never exceeds `9`, so the index will always be a single character.

The output of an empty map of a 4x2 zoo would look like this:

```
\n
    1   2   3   4  \n
  +---+---+---+---+\n
1 |               |\n
  +   +   +   +   +\n
2 |               |\n
  +---+---+---+---+\n
```

After some commands the output of a 4x2 zoo could look like this:

```
\n
    1   2   3   4  \n
  +---+---+---+---+\n
1 |SLi SLi|ADo ADo|\n
  +---+---+   +   +\n
2 |       |ADo A  |\n
  +---+---+---+---+\n
```

This zoo contains a savanna enclosure of size 2x1 with 2 lions and one aquarium of size 2x2 with three dolphins.

</details>

<details>
<summary><h3>Program Loop</h3></summary>

The user can print information about the zoo, build enclosures and buy animals by typing commands in the command line
interface.

The following question and command prompt should be printed every time a user is asked to input a command:

```
\n
What do you want to do?\n
 > 
```

Note the leading and trailing space!

If the user enters an unknown command, this causes an error. Additionally, all entered commands should be checked for the errors specified in their description. If there is an error while parsing a
command, print the correct error message
(see [Return Values and Error Messages](#return-values-and-error-messages)) and proceed by prompting the user for
input again with the question and the command prompt.

After a command has been successfully executed, prompt the user for input again with the question and the command
prompt (except command `quit`).

All possible commands are listed below:

<details>
<summary><h5>Command quit</h5></summary>

Syntax: `quit`

This command is the only way to stop the program. The program should release all its resources
and terminate with the return value `0`.

**Error Handling**

The following errors must be handled (see [Return Values and Error Messages](#return-values-and-error-messages)):

- The command was called with too many or too few parameters

</details>

<details>
<summary><h5>Command info</h5></summary>

Syntax: `info` or `info <FIELD_COLUMN> <FIELD_ROW>`

This command can either be called with zero or two parameters.

If there are no parameters passed to the command, it should show some general information about the zoo:

```
Zoo Name: <ZOO_NAME>\n
Money: <MONEY> coin(s)\n
Number of Animals: <NUMBER_OF_ANIMALS>\n
Empty fields: <EMPTY_FIELDS>\n
Empty enclosures: <EMPTY_ENCLOSURES>\n
```

where

- `<ZOO_NAME>` should be replaced by the name of the zoo,
- `<MONEY>` should be replaced by the amount of coins left,
- `<NUMBER_OF_ANIMALS>` should be replaced by the total amount of animals on the map,
- `<EMPTY_FIELDS>` should be replaced by the amount of fields that are not part of an enclosure, and
- `<EMPTY_ENCLOSURES>` should be replaced by the amount of enclosures without any animals.

If however there are two arguments passed to the command, they should be interpreted as coordinates in
the format `info <FIELD_COLUMN> <FIELD_ROW>` specifying a specific field of the map.

If there is an enclosure on this field, the following information message should be printed:

```
Enclosure: <ENCLOSURE_TYPE>\n
List of inhabitants:\n
<ANIMAL_LIST>
```

with `<ANIMAL_LIST>` being a list of each animal that has been added to this enclosure printed as follows (ordered by 
their insertion time starting with the first animal to be placed in this enclosure):

```
- <ANIMAL_TYPE> "<ANIMAL_NAME>" of age <ANIMAL_AGE>: <ANIMAL_SPECIFIC_TRAIT>\n
```

where

- `<ENCLOSURE_TYPE>` should be replaced by the enclosure type (`Savanna`, `Forest` or `Aquarium`),
- `<ANIMAL_TYPE>` should be replaced by the animal's type (`Lion`, `Giraffe`, `Gorilla` or `Dolphin`),
- `<ANIMAL_NAME>` should be replaced by the animal's name,
- `<ANIMAL_AGE>` should be replaced by the animal's age, and
- `<ANIMAL_SPECIFIC_TRAIT>` should be replaced by the animal's specific trait (see [Animals](description/Animal.md)).

If there are no animals in the enclosure, `<ANIMAL_LIST>` should be omitted.

**Error Handling**

The following errors must be handled (see [Return Values and Error Messages](#return-values-and-error-messages)):

- The command was called with too many or too few parameters
- The command was called with two parameters and the field column and/or row is not an integer or not in range
- The command was called with two parameters and there is no enclosure at this position

</details>

<details>
<summary><h5>Command shop</h5></summary>

Syntax: `shop`

This command shows some information about the shop:

```
Welcome to the "<SHOP_NAME>"!\n
\n
The following are our prices for the given enclosure types per field:\n
- Savanna:   1000 coins\n
- Forest:    3000 coins\n
- Aquarium: 10000 coins\n
\n
We have the following animals for sale:\n
<ANIMAL_LIST>
```

with `<ANIMAL_LIST>` being a list of each animal in the shop printed as follows (ordered by their occurrence in the config file):

```
- <ANIMAL_TYPE> "<ANIMAL_NAME>": <ANIMAL_PRICE> coins\n
```

where

- `<SHOP_NAME>` should be replaced by the name of the shop from the config file,
- `<ANIMAL_PRICE>` should be replaced by the price of the given animal (see [Animals](description/Animal.md)),
- `<ANIMAL_TYPE>` should be replaced by type of the given animal (`Lion`, `Giraffe`, `Gorilla` or `Dolphin`), and
- `<ANIMAL_NAME>` should be replaced by the name of the given animal.

If there are no animals in the shop, `<ANIMAL_LIST>` should be omitted.

**Error Handling**

The following errors must be handled (see [Return Values and Error Messages](#return-values-and-error-messages)):

- The command was called with too many or too few parameters

</details>

<details>
<summary><h5>Command map</h5></summary>

Syntax: `map`

This command activates or deactivates the output of the map.

Initially the output of the map is active.
If the output of the map is active and the command `map` is entered, the output is deactivated.
For all further commands, the map is not printed anymore.

If the output of the map is not active and the command `map` is entered, the output is activated.
The map is printed once immediately. The output of the map then stays active for the following commands.

**Error Handling**

The following errors must be handled (see [Return Values and Error Messages](#return-values-and-error-messages)):

- The command was called with too many or too few parameters

</details>

<details>
<summary><h5>Command build</h5></summary>

With the command `build` the user can build different enclosures.

Syntax: `build <ENCLOSURE_TYPE> <FIELD_COLUMN> <FIELD_ROW> <ENCLOSURE_WIDTH> <ENCLOSURE_HEIGHT>`

where

- `<ENCLOSURE_TYPE>` is the type of the enclosure (`Savanna`, `Forest` or `Aquarium`),
- `<FIELD_COLUMN>` is the column coordinate of the top left field of the new enclosure,
- `<FIELD_ROW>` is the row coordinate of the top left field of the new enclosure,
- `<ENCLOSURE_WIDTH>` is the width of the new enclosure, and
- `<ENCLOSURE_HEIGHT>` is the height of the new enclosure.

If the command was successful, the enclosure should be created and placed at the given position. The money of
the zoo should be reduced by the total amount calculated from the size of the new enclosure and the price per
enclosure field of the given type mentioned in the shop (see Command `shop`).

Afterward, the map should be printed if active. If the map output is deactivated, nothing should be printed.

If the command was not successful, the money should not be reduced and no enclosure should be built.

**Error Handling**

The following errors must be handled (see [Return Values and Error Messages](#return-values-and-error-messages)):

- The command was called with too many or too few parameters
- The given enclosure type does not exist
- The field column and/or row are not integers or not in range
- The width and/or height are not integers greater than 0
- There is not enough money to build this enclosure
- The enclosure does not fit into the selected part of the map (it is too big or there are already
  enclosures within that range)

</details>

<details>
<summary><h5>Command buy</h5></summary>

The user can buy animals and add them to enclosures with the `buy` command.

Syntax: `buy <ANIMAL_NAME> <FIELD_COLUMN> <FIELD_ROW>`

where

- `<ANIMAL_NAME>` is the name (case-insensitive!) of the animal shown in the shop,
- `<FIELD_COLUMN>` is the column coordinate of a field that is part of the enclosure where the animal should be 
  placed, and
- `<FIELD_ROW>` is the row coordinate of a field that is part of the enclosure where the animal should be placed.

Animals are not placed directly on the field specified by the parameters. Instead, **the field coordinates are only
used to define which enclosure the animal should be added to.**

There are some constraints for which animals are allowed to be in which enclosure and with whom. These are
described in more detail in the [Enclosure description](./description/Enclosure.md).

If the command was successful, the animal should be removed from the shop and added to the enclosure the given
field is a part of. The available money should be reduced by the price of the animal. How the price for each animal
type is calculated can be found in the [Animal description](./description/Animal.md).

Afterward, the map should be printed if active. If the map output is deactivated, nothing should be printed.

If the command was not successful, the animal should stay in the shop and no money should be paid.

**Error Handling**

The following errors must be handled (see [Return Values and Error Messages](#return-values-and-error-messages)):

- The command was called with too many or too few parameters
- There is no animal in the shop with the given name
- The field column and/or row is not an integer or not in range
- There is not enough money to buy this animal
- The selected field is not part of an enclosure 
- The maximum number of animals in this enclosure has already been reached
- The animal is not allowed to be in the given enclosure

</details>

<details>
<summary><h5>Command rate</h5></summary>

The user can use the `rate` command to get an overall rating for the current status of the created zoo.

Syntax: `rate`

This rating is printed the following way:

```
Individual ratings of enclosures:\n
<ENCLOSURE_LIST>
Your zoo has an overall rating of <OVERALL_RATING>!\n
```

with `<ENCLOSURE_LIST>` being a list of each enclosure printed as follows 
(ordered by their top left field in the map from left to right and top to bottom):

```
- <ENCLOSURE_TYPE> (<FIELD_COLUMN>/<FIELD_ROW>): <INDIVIDUAL_RATING>\n
```

where

- `<OVERALL_RATING>` should be replaced by the overall rating of the zoo,
- `<ENCLOSURE_TYPE>` should be replaced by the type of the enclosure (`Savanna`, `Forest` or `Aquarium`),
- `<FIELD_COLUMN>` is the column coordinate of the top left field of the enclosure,
- `<FIELD_ROW>` is the row coordinate of the top left field of the enclosure, and
- `<INDIVIDUAL_RATING>` should be replaced by the individual rating of this enclosure.

How the individual rating of an enclosure is calculated is described in the [Enclosure description](./description/Enclosure.md). 
The overall rating of the zoo is the sum of the ratings of all enclosures.

If there are no enclosures on the map, `<ENCLOSURE_LIST>` should be omitted and the overall rating is `0`.

Afterward, the map should be printed if active. If the map output is deactivated, nothing should be printed.

**Error Handling**

The following errors must be handled (see [Return Values and Error Messages](#return-values-and-error-messages)):

- The command was called with too many or too few parameters

</details>

</details>

## Return Values and Error Messages

The program has to react to errors during the runtime and print the corresponding error messages and/or return the
correct return values. You can find all error messages that should be printed and all return values in the table below.

Only one error should be printed at once. If multiple errors occur at the same time,
only the highest message in the below table should be printed.

| Return Value | Error Message                                            | Meaning                                                                             | Program Phase                            |
|--------------|----------------------------------------------------------|-------------------------------------------------------------------------------------|------------------------------------------|
| 0            | -                                                        | The program terminated successfully                                                 | -                                        |
| 1            | `[ERROR] Wrong number of parameters!\n`                  | The wrong number of command line parameters was entered                             | Starting the Program                     |
| 2            | `[ERROR] Invalid file!\n`                                | The config file could not be opened or does not start with the correct magic number | Starting the Program                     |
| 3            | `[ERROR] Invalid amount of starting money!\n`            | The amount of starting money is invalid                                             | Starting the Program                     |
| 4            | `[ERROR] Invalid zoo dimensions!\n`                      | The parameters width or height for the zoo are invalid                              | Starting the Program                     |
|              | `[ERROR] Entered command not found!\n`                   | The entered command was not found                                                   | All Commands                             |
|              | `[ERROR] Wrong number of parameters for this command!\n` | The wrong number of parameters was entered for the specific command                 | All Commands                             |
|              | `[ERROR] No enclosure with given type!\n`                | The given enclosure type is not one of the possible types                           | Command build                            |
|              | `[ERROR] No animal with given name in the shop!\n`       | The given name does not belong to an animal in the shop                             | Command buy                              |
|              | `[ERROR] Invalid field position!\n`                      | The given field column and/or row is not an integer or not in range                 | Command info, Command build, Command buy |
|              | `[ERROR] Invalid width or height!\n`                     | The given width and/or height is not an integer greater than 0                      | Command build                            |
|              | `[ERROR] There is not enough money!\n`                   | There is not enough money to buy the given animal or build the given enclosure      | Command build, Command buy               |
|              | `[ERROR] Field is not part of an enclosure!\n`           | The given field is not part of an enclosure                                         | Command info, Command buy                |
|              | `[ERROR] Enclosure does not fit!\n`                      | The given enclosure is too big or overlaps with an existing enclosure               | Command build                            |
|              | `[ERROR] There is not enough space in this enclosure!\n` | The maximum number of animals in this enclosure has already been reached            | Command buy                              |
|              | `[ERROR] This animal is not allowed here!\n`             | The given animal is not allowed in the enclosure that the given field is part of    | Command buy                              |


## Example Outputs

<details>
<summary><h3>Example Output 1</h3></summary>

The following example output was created using `./a1 zOOP configs/shop_config.csv 20000 3 3` to start the program.
```
\n
Welcome to your Zoo "zOOP"!\n
This zoo has a size of 3 x 3!\n
\n
    1   2   3  \n
  +---+---+---+\n
1 |           |\n
  +   +   +   +\n
2 |           |\n
  +   +   +   +\n
3 |           |\n
  +---+---+---+\n
\n
What do you want to do?\n
 > info\n
Zoo Name: zOOP\n
Money: 20000 coin(s)\n
Number of Animals: 0\n
Empty fields: 9\n
Empty enclosures: 0\n
\n
What do you want to do?\n
 > shop\n
Welcome to the "shOOP"!\n
\n
The following are our prices for the given enclosure types per field:\n
- Savanna:   1000 coins\n
- Forest:    3000 coins\n
- Aquarium: 10000 coins\n
\n
We have the following animals for sale:\n
- Lion "Eisi": 7000 coins\n
- Giraffe "Hans": 5100 coins\n
- Gorilla "Lukas": 1975 coins\n
- Dolphin "Felix": 9900 coins\n
\n
What do you want to do?\n
 > build savanna 2 2 2 2\n
\n
    1   2   3  \n
  +---+---+---+\n
1 |           |\n
  +   +---+---+\n
2 |   |S   S  |\n
  +   +   +   +\n
3 |   |S   S  |\n
  +---+---+---+\n
\n
What do you want to do?\n
 > buy eisi 2 2\n
\n
    1   2   3  \n
  +---+---+---+\n
1 |           |\n
  +   +---+---+\n
2 |   |SLi S  |\n
  +   +   +   +\n
3 |   |S   S  |\n
  +---+---+---+\n
\n
What do you want to do?\n
 > info\n
Zoo Name: zOOP\n
Money: 9000 coin(s)\n
Number of Animals: 1\n
Empty fields: 5\n
Empty enclosures: 0\n
\n
What do you want to do?\n
 > info 2 2\n
Enclosure: Savanna\n
List of inhabitants:\n
- Lion "Eisi" of age 17: Mane length is 20 cm!\n
\n
What do you want to do?\n
 > rate\n
Individual ratings of enclosures:\n
- Savanna (2/2): 12\n
Your zoo has an overall rating of 12!\n
\n
    1   2   3  \n
  +---+---+---+\n
1 |           |\n
  +   +---+---+\n
2 |   |SLi S  |\n
  +   +   +   +\n
3 |   |S   S  |\n
  +---+---+---+\n
\n
What do you want to do?\n
 > quit\n
```

</details>

<details>
<summary><h3>Example Output 2</h3></summary>

The following example output was created using `./a1 zOOP configs/shop_config.csv 40000 3 3` to start the program.

```
\n
Welcome to your Zoo "zOOP"!\n
This zoo has a size of 3 x 3!\n
\n
    1   2   3  \n
  +---+---+---+\n
1 |           |\n
  +   +   +   +\n
2 |           |\n
  +   +   +   +\n
3 |           |\n
  +---+---+---+\n
\n
What do you want to do?\n
 > build aquarium 1 1 1 1\n
\n
    1   2   3  \n
  +---+---+---+\n
1 |A  |       |\n
  +---+   +   +\n
2 |           |\n
  +   +   +   +\n
3 |           |\n
  +---+---+---+\n
\n
What do you want to do?\n
 > buy felix 1 1\n
\n
    1   2   3  \n
  +---+---+---+\n
1 |ADo|       |\n
  +---+   +   +\n
2 |           |\n
  +   +   +   +\n
3 |           |\n
  +---+---+---+\n
\n
What do you want to do?\n
 > build forest 2 1 1 2\n
\n
    1   2   3  \n
  +---+---+---+\n
1 |ADo|F  |   |\n
  +---+   +   +\n
2 |   |F  |   |\n
  +   +---+   +\n
3 |           |\n
  +---+---+---+\n
\n
What do you want to do?\n
 > buy luki 2 2\n
[ERROR] No animal with given name in the shop!\n
\n
What do you want to do?\n
 > buy lukas 2 2\n
\n
    1   2   3  \n
  +---+---+---+\n
1 |ADo|FGo|   |\n
  +---+   +   +\n
2 |   |F  |   |\n
  +   +---+   +\n
3 |           |\n
  +---+---+---+\n
\n
What do you want to do?\n
 > rate\n
Individual ratings of enclosures:\n
- Aquarium (1/1): 3\n
- Forest (2/1): 8\n
Your zoo has an overall rating of 11!\n
\n
    1   2   3  \n
  +---+---+---+\n
1 |ADo|FGo|   |\n
  +---+   +   +\n
2 |   |F  |   |\n
  +   +---+   +\n
3 |           |\n
  +---+---+---+\n
\n
What do you want to do?\n
 > quit\n
```

</details>