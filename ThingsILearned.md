## cin vs getline

Originally, **cin** was used to obtain user input. However, this approach had limitations when parsing the input into separate parts, specifically the initial command "uplink_connect" and the address. Using **cin** alone would only capture the "uplink_connect" part as the space would indicate the end of the input.

To address this, **getline** was employed to read the entire command, allowing for input in the format "uplink_connect xxx.xxx.xxx.xxx". By using **getline**, the entire line of input, including spaces, could be retrieved as a single string. This enabled the code to extract the necessary information, such as separating the command and the address, for comparison with the **ipaddress** variable.
