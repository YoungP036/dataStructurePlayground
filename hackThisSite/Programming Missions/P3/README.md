This level is about reversing an encryption algorithm.



The original text is a bunch of fake serial numbers. Click here to see some examples of what they look like. The PHP-code which is used for the encryption is given below:




    <?php

      //------------------------------------------------------------------------------------
      function evalCrossTotal($strMD5)
      {
          $intTotal = 0;
          $arrMD5Chars = str_split($strMD5, 1);
          foreach ($arrMD5Chars as $value)
          {
              $intTotal += '0x0'.$value;
          }
          return $intTotal;
      }//-----------------------------------------------------------------------------------



      //------------------------------------------------------------------------------------
      function encryptString($strString, $strPassword)
      {
          // $strString is the content of the entire file with serials
          $strPasswordMD5 = md5($strPassword);
          $intMD5Total = evalCrossTotal($strPasswordMD5);
          $arrEncryptedValues = array();
          $intStrlen = strlen($strString);
          for ($i=0; $i<$intStrlen; $i++)
          {
              $arrEncryptedValues[] =  ord(substr($strString, $i, 1))
                                       +  ('0x0' . substr($strPasswordMD5, $i%32, 1))
                                       -  $intMD5Total;
              $intMD5Total = evalCrossTotal(substr(md5(substr($strString,0,$i+1)), 0, 16)
                                       .  substr(md5($intMD5Total), 0, 16));
          }
          return implode(' ' , $arrEncryptedValues);
      }//-----------------------------------------------------------------------------------

    ?>





This is the encrypted text:

-157 -129 -145 -192 -135 -162 -145 -178 -173 -185 -166 -198 -131 -160 -157 -168 -127 -178 -166 -186 -155 -167 -127 -174 -132 -167 -214 -172 -121 -157 -121 -215 -101 -226 -182 -199 -209 -171 -202 -182 -137 -177 -154 -180 -132 -211 -190 -171 -187 -158 -156 -146 -170 -180 -127 -154 -194 -171 -197 -224 -173 -133 -128 -192 -155 -164 -150 -192 -126 -167 -143 -190 -172 -174 -188 -184 -199 -213 -183 -175 -142 -121 -144 -207 -193 -148 -139 -198 -132 -139 -116 -190 -181 -148 -193 -195 -165 -209 -154 -206




Send the last one of the serial numbers you decrypted as answer.


You have 120 seconds time to send the solution