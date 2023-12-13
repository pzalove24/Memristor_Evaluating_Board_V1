// include opensource lib
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP4725.h>
#include <ADS1X15.h>
#include <ArduinoJson.h>
#include <MD_AD9833.h>
// include lib IC_Operation
#include "ADC_Read/ADC_Read.h"
#include "DAC_Bias/DAC_Bias.h"
// include lib BoardOperation
#include "Current_Limiter/Current_Limiter.h"

// Current_Limiter current_limiter(7, 6, 5, 4); // pin digital number

// void handleCurrentComplianceTask(void *pvParameters)
// {
//   Serial.begin(9600);
//   current_limiter.init();
//   char current_set_from_user = Serial.read();

//   switch (current_set_from_user)
//   {
//   case 'one_mA':
//     current_limiter.one_mA();
//     Serial.println(current_set_from_user);
//     break;
//   case 'hundred_uA':
//     current_limiter.hundred_uA();
//     Serial.println(current_set_from_user);
//     break;
//   case 'ten_uA':
//     current_limiter.ten_uA();
//     Serial.println(current_set_from_user);
//     break;
//   case 'one_uA':
//     current_limiter.one_uA();
//     Serial.println(current_set_from_user);
//     break;
//   default:
//     Serial.println("Current Compliance selection is needed");
//     break;
//   }
// }

// void handleReadyStatus(void *pvParameters)
// {
//   Serial.begin(9600);

//   while (1)
//   {
//     Serial.println("Arduino is ready");
//     delay(1000);
//   }
// }

void handleTwCommand(String data)
{
  // Handle "tw" command
  Serial.println("Handling tw command");
  Serial.println("Ready");
  // Add your tw command logic here
}

void handleMrwCommand(String data)
{
  // Handle "mrw" command
  Serial.println("Handling mrw command");
  Serial.println("Ready");
  // Add your mrw command logic here
}

void handleIvpwCommand(String data)
{
  // Handle "ivpw" command
  Serial.println("Handling ivpw command");
  Serial.println("Ready");
  // Add your ivpw command logic here
}

void splitString(const char *input, char *tokens[], size_t maxTokens, char delimiter)
{
  size_t tokenIndex = 0;
  const char *start = input;

  while (*input && tokenIndex < maxTokens)
  {
    if (*input == delimiter)
    {
      size_t length = input - start;
      tokens[tokenIndex] = (char *)malloc(length + 1);
      strncpy(tokens[tokenIndex], start, length);
      tokens[tokenIndex][length] = '\0';
      start = input + 1; // Move start to the character after the delimiter
      tokenIndex++;
    }
    input++;
  }

  // Handle the last token
  size_t length = input - start;
  tokens[tokenIndex] = (char *)malloc(length + 1);
  strncpy(tokens[tokenIndex], start, length);
  tokens[tokenIndex][length] = '\0';
}

void freeTokens(char *tokens[], size_t numTokens)
{
  for (size_t i = 0; i < numTokens; ++i)
  {
    free(tokens[i]);
  }
}

void printEachTokens(char *tokens[], size_t numTokens)
{
  for (size_t i = 0; i < numTokens; ++i)
  {
    Serial.println(tokens[i]);
  }
}

void sendTokensInSingleLine(char *tokens[], size_t numTokens)
{
  Serial.print("Confirm,");
  for (size_t i = 0; i < numTokens; ++i)
  {
    Serial.print(tokens[i]);
    if (i < numTokens - 1)
    {
      Serial.print(",");
    }
  }
  Serial.println(); // Add a newline character at the end
}

// bool isStringInList(const char *tokens[], const char *stringList[], size_t listSize)
// {
//   for (size_t i = 0; i < listSize; ++i)
//   {
//     if (strcmp(tokens[0], stringList[i]) == 0)
//     {
//       return true; // Match found
//     }
//   }
//   return false; // No match found
// }

void processTokens(char *tokens[], size_t numTokens)
{
}

//** matching benchmark type **//
const char *testSerialPortWeb[] = {"tw"};                                                   // listIndex 0
const char *manualOperationWeb[] = {"mrw", "mww"};                                          // listIndex 1
const char *standardBenchmarkPulseWeb[] = {"ivpw", "llpw", "oopw", "dipw", "cupw", "cppw"}; // listIndex 2
const char *standardBenchmarkSweepWeb[] = {"ivsw", "llsw", "oosw", "disw", "cusw", "cpsw"}; // listIndex 3
const char *stabilityBenchmarkPulseWeb[] = {"ecpw", "rtpw"};                                // listIndex 4
const char *stabilityBenchmarkSweepWeb[] = {"ecsw", "rtsw"};                                // listIndex 5
const char *advancedBenchmarkPulseWeb[] = {"ivmcpw", "ivmvpw"};                             // listIndex 6
const char *advancedBenchmarkSweepWeb[] = {"ivmcsw", "ivmvsw"};                             // listIndex 7

const char **lists[] = {
    testSerialPortWeb,
    manualOperationWeb,
    standardBenchmarkPulseWeb,
    standardBenchmarkSweepWeb,
    stabilityBenchmarkPulseWeb,
    stabilityBenchmarkSweepWeb,
    advancedBenchmarkPulseWeb,
    advancedBenchmarkSweepWeb};

size_t numLists = sizeof(lists) / sizeof(lists[0]);

size_t listSizes[] = {
    sizeof(testSerialPortWeb) / sizeof(testSerialPortWeb[0]),
    sizeof(manualOperationWeb) / sizeof(manualOperationWeb[0]),
    sizeof(standardBenchmarkPulseWeb) / sizeof(standardBenchmarkPulseWeb[0]),
    sizeof(standardBenchmarkSweepWeb) / sizeof(standardBenchmarkSweepWeb[0]),
    sizeof(stabilityBenchmarkPulseWeb) / sizeof(stabilityBenchmarkPulseWeb[0]),
    sizeof(stabilityBenchmarkSweepWeb) / sizeof(stabilityBenchmarkSweepWeb[0]),
    sizeof(advancedBenchmarkPulseWeb) / sizeof(advancedBenchmarkPulseWeb[0]),
    sizeof(advancedBenchmarkSweepWeb) / sizeof(advancedBenchmarkSweepWeb[0]),
};

bool isStringInList(const char *input, const char *list[], size_t listSize)
{
  for (size_t j = 0; j < listSize; ++j)
  {
    if (strcmp(input, list[j]) == 0)
    {
      return true; // Match found
    }
  }
  return false; // No match found in the current list
}

//** END **//

//** Function Selection Benchmark **/
void processCommand(size_t listIndex, String data)
{
  switch (listIndex)
  {
  case 0:
    // Handle "tw" command
    Serial.println("Handling tw command");
    Serial.println("Ready");
    // Add your tw command logic here
    break;

  case 1:
    // Handle "mrw" or "mww" command
    Serial.println("Handling mrw or mww command");
    Serial.println("Ready");
    // Add your mrw or mww command logic here
    break;

  case 2:
    // Handle "mrw" or "mww" command
    Serial.println("standardBenchmarkPulseWeb");
    Serial.println("Ready");
    // Add your mrw or mww command logic here
    break;

  case 3:
    // Handle "mrw" or "mww" command
    Serial.println("standardBenchmarkSweepWeb");
    Serial.println("Ready");
    // Add your mrw or mww command logic here
    break;

  case 4:
    // Handle "mrw" or "mww" command
    Serial.println("stabilityBenchmarkPulseWeb");
    Serial.println("Ready");
    // Add your mrw or mww command logic here
    break;

  case 5:
    // Handle "mrw" or "mww" command
    Serial.println("stabilityBenchmarkSweepWeb");
    Serial.println("Ready");
    // Add your mrw or mww command logic here
    break;

  case 6:
    // Handle "mrw" or "mww" command
    Serial.println("advancedBenchmarkPulseWeb");
    Serial.println("Ready");
    // Add your mrw or mww command logic here
    break;

  case 7:
    // Handle "mrw" or "mww" command
    Serial.println("advancedBenchmarkSweepWeb");
    Serial.println("Ready");
    // Add your mrw or mww command logic here
    break;
  default:
    Serial.println("Unknown command");
    Serial.println("Ready");
    break;
  }
}

//** END **//

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  if (Serial.available() > 0)
  {
    // Read the incoming data until a newline character is received
    String data = Serial.readStringUntil('\n');

    // Convert the String to a char array
    char buffer[data.length() + 1];
    data.toCharArray(buffer, sizeof(buffer));

    // Split the data based on commas
    const size_t maxTokens = 7; // Maximum number of tokens in your example
    char *tokens[maxTokens];

    splitString(buffer, tokens, maxTokens, ',');

    // Print the tokens
    printEachTokens(tokens, maxTokens);

    // Send all tokens in a single line through the serial port
    sendTokensInSingleLine(tokens, maxTokens);

    // Check if the input matches any string in the lists
    for (size_t i = 0; i < numLists; ++i)
    {
      const char **currentList = lists[i];
      size_t listSize = listSizes[i];

      if (isStringInList(tokens[0], currentList, listSize))
      {
        Serial.println("Input matched a string in the lists");
        processCommand(i, tokens[0]);
        return; // Match found, exit loop
      }
    }

    Serial.println("Input does not get matched a string in the lists");

    if (tokens[0])

      // Free allocated memory
      freeTokens(tokens, maxTokens);
  }
  else
  {
    Serial.println("Ready");
    delay(1000);
  }

  // char WebsiteCommand = Serial.read();

  // switch (WebsiteCommand)
  // {
  // case 'Manual_Current_Range':
  //   current_limiter.setCurrentRange('A');
  //   Serial.println('x');
  //   break;

  // default:
  //   break;
  // }
}