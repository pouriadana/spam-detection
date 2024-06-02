# Spam Detection System

## Overview
The Spam Detection System is a sophisticated C++ application designed to identify and filter spam messages. Utilizing a (yet to be comprehensive) list of spam keywords, the program meticulously scans messages of any length, including those with multiple paragraphs and newline characters.

## Features
- **Dynamic Spam Word Detection**: Employs a text file (`SpamKeywords.txt`) containing a list of spam indicators, offering easy updates and customization.
- **Multi-Paragraph Analysis**: Capable of reading and analyzing messages with complex structures, preserving the integrity of the detection process.
- **Efficient Algorithm**: Implements a high-performance algorithm in `SpamDetector.cpp` for rapid and accurate spam identification.

## Installation
To install the Spam Detection System, clone this repository and compile the `SpamDetector.cpp` using your preferred C++ compiler.

```bash
git clone https://github.com/pouriadana/spam-detection-system.git
cd spam-detection-system/src
g++ -o SpamDetector SpamDetector.cpp
```

## Usage
Run the compiled application and follow the on-screen prompts to input the message for spam analysis.
```bash
./SpamDetector
```

## Contributing
Contributions to the Spam Detection System are welcome. Please ensure to update tests as appropriate.

## License
Distributed under the GPL 3.0 License. See LICENSE for more information.

## Contact
Pouria Dana - pouriadana73@gmail.com Project Link: https://github.com/pouriadana/spam-detection-system
