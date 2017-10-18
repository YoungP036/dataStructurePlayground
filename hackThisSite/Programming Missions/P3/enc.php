<?php
    // $input="99Z-KH5-OEM-240-1.1
    // QGG-V33-OEM-0B1-1.1
    // Z93-Z29-OEM-BNX-1.1
    // IQ0-PZI-OEM-PK0-1.1
    // UM4-VDL-OEM-B9O-1.1
    // L0S-4R2-OEM-UQL-1.1
    // JBL-EYQ-OEM-ABB-1.1
    // NL1-3V3-OEM-L4C-1.1
    // 7CQ-1ZR-OEM-U3I-1.1
    // XX0-IHL-OEM-5XK-1.1
    // KJQ-RXG-OEM-TW8-1.1
    // OZR-LW1-OEM-5EM-1.1
    // 0B8-6K5-OEM-EFN-1.1
    // OE2-20L-OEM-SSI-1.1
    // 0ME-HAE-OEM-9XB-1.1";
    $input="0ME-HAE-OEM-9XB-1.1";
    // $key="22222222222222222222222222222222222222222222222222222222222";
    $key="111111111111111111111111111111111111111111111111111111111111";
    echo encryptString($input, $key);
    echo "\n";
      //------------------------------------------------------------------------------------
      function evalCrossTotal($strMD5)
      {
          $intTotal = 0;
          $arrMD5Chars = str_split($strMD5, 1);//split into strings of len 1
          //for each char 
          foreach ($arrMD5Chars as $value)
          {
              //concat with '0x0', php will recognize as hex and do base 16 arithmatic
              $intTotal += '0x0'.$value;
          }
          return $intTotal;
      }//-----------------------------------------------------------------------------------



      //------------------------------------------------------------------------------------
      function encryptString($strString, $strPassword)
      {
          $strPasswordMD5 = md5($strPassword);//hash pass
          $intMD5Total = evalCrossTotal($strPasswordMD5);//base 16 sum of pw hash
          $arrEncryptedValues = array();
          $intStrlen = strlen($strString);//get plaintext len
          for ($i=0; $i<$intStrlen; $i++)
          {
            //arrEnc[i]=asci@plaintext[i]+hex@pwHash[i%32]-b16TotalSum
            $arrEncryptedValues[] =  ord(substr($strString, $i, 1))
                                       +  ('0x0' . substr($strPasswordMD5, $i%32, 1))
                                       -  $intMD5Total;
//b16sum(1st 16 char of md5(first i+1 chars of plaintext)) concat with first 16 char from last sum
            $intMD5Total = evalCrossTotal(substr(md5(substr($strString,0,$i+1)), 0, 16)
                                       .  substr(md5($intMD5Total), 0, 16));
          }
          //return array elements in string form
          return implode(' ' , $arrEncryptedValues);
      }//-----------------------------------------------------------------------------------

    ?>