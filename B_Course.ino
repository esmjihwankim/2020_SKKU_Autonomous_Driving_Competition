

/* 
 * Functions get triggered to the 'Stop Lines' 
 * 
 * Timer Declaration 
 * Only used for performing missions
 * 
 * 타이머를 이용해 코스의 각 구간에서 미션을
 * 수행하면서도 async 로 센서의 값을 받을 수 있게 하여야 함 
 */



inline void proceedMission()
{
  switch(iStageNumber)
  {
      case 1:
        Serial.println("#100 Parallel Parking");
        parallelParking();
        break;

      case 2:
        Serial.println("#200 Intersection 1");
        intersection(false);
        break;

      case 3: 
        Serial.println("#300 Intersection 2");
        intersection(false);
        break;

      case 4:
        Serial.println("#400 Prepare Backward Parking");
        prepareBackwardParking();
        break;
      
      case 5:
        Serial.println("#400 Backward Parking #1");
        backwardParking();
        break;

      case 6:
        Serial.println("#500 Backward Parking #2");
        escapeBackwardParking();

      case 7: 
        Serial.println("#600 Impediment Avoidence");
        avoidence();
        break;

      case 8:
        Serial.println("#700 Finish Line");  
        timedStop(2000);
        break;
        
      default:
        Serial.println("#Error:Unidentified Course Location");
        break;
    }
}
