

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
        HM10.write("#100 Parallel Parking\n");
        parallelParking();
        break;

      case 2:
        HM10.write("#200 Intersection 1\n");
        timedStop(10);
        timedDrive(0, 0.1, 1, NULL, true);
        timedDrive(0, 0.1, 10, NULL, true);
        break;

      case 3: 
        HM10.write("#300 Intersection 2\n");
        timedStop(10);
        timedDrive(0, 0.1, 1, NULL, false);
        timedDrive(0, 0.1, 10, NULL, true);
        break;

      case 4:
        HM10.write("#400 Backward Parking\n");
        backwardParking();
        break;
      
      case 5: 
        HM10.write("#500 Avoidence\n");
        avoidence();
        break;

      case 6:
        HM10.write("#600 Finish Line\n");  
        timedStop(2000);
        break;
                
      default:
        HM10.write("#Error:Unidentified Course Location\n");
        break;
    }
}
