# ESP32BadUSB
Badusb script that turns off real time protection and triggers a revers shell locally, in both AZERTY and QWERTY computers.

Tested on  ESP32 S3, no need for SDcard.

# Usage
in the payload replace #PHASE2 172.16.0.4 with private IP of listener device
and replace   Keyboard.begin (KeyboardLayout_fr_FR);  by  Keyboard.begin(); for USA QWERTY computer.


## ⚠️ Legal Disclaimer

This project is provided strictly for **educational and authorized testing purposes only**. 

By using this software, you agree that:

- You will only run this on devices and networks **you own**, or **have explicit written permission** to test.
- Unauthorized access to computer systems is **illegal** under laws such as the **Computer Fraud and Abuse Act (CFAA)** in the United States, the **Computer Misuse Act** in the UK, and equivalent legislation in most other countries.
- Using this tool against systems without consent may result in **criminal charges, civil liability, and other legal consequences**.
- The author(s) of this repository **assume no liability** and are **not responsible** for any misuse or damage caused by this tool.

**Use responsibly. You are solely responsible for your actions.**
