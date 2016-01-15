

void search_line(int RorL){

int oldR = nxt_motor_get_count(DRIVE_R);
int oldL = nxt_motor_get_count(DRIVE_L);
int nowR = nxt_motor_get_count(DRIVE_R);
int nowL = nxt_motor_get_count(DRIVE_L);
int tyokkaku = 720;
int flg = 0;
int seach_range = 80;
int speed = 40;
int shani = 30;
U16 ir = 0;

if(RorL ==1){/*r = 0; 引数が右側走行だったら */
		while(nowR - oldR <= seach_range){
		nowR = nxt_motor_get_count(DRIVE_R);
		steer_angle(720);
		Motor_rotate(DRIVE_R, speed, 1);/* 右向け */
		nxt_motor_set_speed(DRIVE_L, 0, 1);
		ir = ecrobot_get_light_sensor(IR);
		if(ir <= (black+shani) && ir >= (black-shani)){
		flg = 1;
		nxt_motor_set_speed(DRIVE_R, -speed, 1);/* 左向け */
		break;}
		systick_wait_ms(4);
		}

	oldR = nxt_motor_get_count(DRIVE_R);

		while(nowR - oldR >= -(seach_range*2)){
		nowR = nxt_motor_get_count(DRIVE_R);
		steer_angle(720);
		nxt_motor_set_speed(DRIVE_R, -speed, 1);/* 左向け */
		nxt_motor_set_speed(DRIVE_L, 0, 1);
		ir = ecrobot_get_light_sensor(IR);
		if(ir <= (black+shani) && ir >= (black-shani) || flg == 1){
		flg == 1;
		nxt_motor_set_speed(DRIVE_R, speed, 1);/* 右向け */
		break;}
		systick_wait_ms(4);
		}

	oldR = nxt_motor_get_count(DRIVE_R);

		while(nowR - oldR <= seach_range){
		nowR = nxt_motor_get_count(DRIVE_R);
		steer_angle(720);
		nxt_motor_set_speed(DRIVE_R, speed, 1);/* 右向け */
		nxt_motor_set_speed(DRIVE_L, 0, 1);
		ir = ecrobot_get_light_sensor(IR);
		if(ir <= (black+shani) && ir >= (black-shani) || flg == 1){
		flg = 1;
		nxt_motor_set_speed(DRIVE_R, -speed, 1);/* 左向け */
		break;}
		systick_wait_ms(4);
		}

	}else{/* 引数が左側走行だったら */

		while(((nowL - oldL)-(nowR - oldR)) <= seach_range){
		nowR = nxt_motor_get_count(DRIVE_R);
		nowL = nxt_motor_get_count(DRIVE_L);
		steer_angle(720);
		nxt_motor_set_speed(DRIVE_R, -speed, 1);/* 左向け */
		nxt_motor_set_speed(DRIVE_L, 0, 1);
		ir = ecrobot_get_light_sensor(IR);
		if(ir <= (black+shani) && ir >= (black-shani)){
		flg == 1;
		nxt_motor_set_speed(DRIVE_R, speed, 1);/* 右向け */
		break;}
		systick_wait_ms(4);
		}

	oldR = nxt_motor_get_count(DRIVE_R);
	oldL = nxt_motor_get_count(DRIVE_L);

		while((nowR - oldR)-(nowL - oldL) <= (seach_range*2)){
		nowR = nxt_motor_get_count(DRIVE_R);
		nowL = nxt_motor_get_count(DRIVE_L);
		steer_angle(720);
		nxt_motor_set_speed(DRIVE_R, speed, 1);/* 右向け */
		nxt_motor_set_speed(DRIVE_L, 0, 1);
		ir = ecrobot_get_light_sensor(IR);
		if(ir <= (black+shani) && ir >= (black-shani) || flg == 1){
		flg = 1;
		nxt_motor_set_speed(DRIVE_R, -speed, 1);/* 左向け */
		break;}
		systick_wait_ms(4);
		}

		while(((nowL - oldL)-(nowR - oldR)) <= seach_range){
		nowR = nxt_motor_get_count(DRIVE_R);
		nowL = nxt_motor_get_count(DRIVE_L);
		steer_angle(720);
		nxt_motor_set_speed(DRIVE_R, -speed, 1);/* 左向け */
		nxt_motor_set_speed(DRIVE_L, 0, 1);
		ir = ecrobot_get_light_sensor(IR);
		if(ir <= (black+shani) && ir >= (black-shani) || flg == 1){
		flg == 1;
		nxt_motor_set_speed(DRIVE_R, speed, 1);/* 右向け */
		break;}
		systick_wait_ms(4);
		}

	}


	if(RorL == 1){/* 引数が右側走行だったら */
		while(ir >= target){/* targetより黒寄りの間繰り返す */
		steer_angle(720);
		nxt_motor_set_speed(DRIVE_R, speed, 1);/* 左向け */
		nxt_motor_set_speed(DRIVE_L, 0, 1);
		ir = ecrobot_get_light_sensor(IR);
		}
	}else if(RorL == 2){
		while(ir >= target){/* targetより黒寄り */
		steer_angle(720);
		nxt_motor_set_speed(DRIVE_R, -speed, 1);/* 右向け */
		nxt_motor_set_speed(DRIVE_L, 0, 1);
		ir = ecrobot_get_light_sensor(IR);
		}
	}
  steer_angle(0);
}
