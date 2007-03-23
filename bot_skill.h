//
// JK_Botti - be more human!
//
// bot_skill.h
//

typedef struct
{
   int pause_frequency; // how often (out of 1000 times) the bot will pause, based on bot skill
   float pause_time[2]; // how long bot pauses (min, max)
   
   float normal_strafe; // how much bot straifes when walking around
   float battle_strafe; // how much bot straifes when attacking enemy
   
   int keep_optimal_distance; // how often bot (out of 1000 times) the bot try to keep at optimum distance of weapon when attacking
   
   float react_delay_min[3]; // reaction delay settings
   float react_delay_max[3]; 
   
   float shootcone_diameter; // bot tries to fire when crosshair is within width of this setting
   float shootcone_minangle; // OR bot aim angle is less than angle set here
   
   // (min/max) Bot doesn't use real origin of target player but instead use data from earlier
   // and does latency prediction based on this data to get player origin. These settings
   // specify ammount of latency used at this skill level.
   float prediction_latency;
   float turn_skill; // BotAim turn_skill, how good bot is at aiming on enemy origin.
   
   int hear_frequency; // how often (out of 100 times) the bot will hear what happens around it.
   
   qboolean can_longjump; // and can longjump.
   
   int random_jump_frequency; // how often (out of 100 times) the bot will do random jump
   int random_jump_duck_frequency; // how often (out of 100 times) the bot will do random duck when random jumping
   int random_duck_frequency; // how often (out of 1000 times) the bot will do random duck jumping in combat mode
   
   int random_longjump_frequency; // how often (out of 100 times) the bot will do random longjump instead of random jump
   
} bot_skill_settings_t;

#ifdef BOTSKILL
bot_skill_settings_t skill_settings[5] = {
   // best skill (lvl1)
   { 5, {0.2/2, 0.5/2}, 10.0, 50.0, 1000, 
     {0.01, 0.07, 0.10}, {0.04, 0.11, 0.15}, 
     150.0, 10.0, 0.100, 5.0,
     100, TRUE, 50, 75, 20, 20 },
   // lvl2
   { 15, {0.5/2, 1.0/2}, 8.0, 30.0, 800,
     {0.02, 0.09, 0.12}, {0.06, 0.14, 0.18},
     175.0, 20.0, 0.200, 3.0,
     80, TRUE, 35, 60, 16, 15 },
   // lvl3
   { 50, {1.0/2, 1.5/2}, 6.0, 15.0, 600,
     {0.03, 0.12, 0.15}, {0.08, 0.18, 0.22},
     200.0, 25.0, 0.300, 2.0,
     70, TRUE, 20, 40, 12, 11 },
   // lvl4
   { 100, {2.0/2, 3.0/2}, 4.0, 5.0, 400,
     {0.04, 0.14, 0.18}, {0.10, 0.21, 0.25},
     250.0, 30.0, 0.400, 1.0,
     50, TRUE, 10, 25, 8, 8 },
   // worst skill (lvl5)
   { 200, {3.0/2, 5.0/2}, 0.5, 1.0, 200,
     {0.05, 0.17, 0.21}, {0.12, 0.25, 0.30},
     300.0, 35.0, 0.500, 0.5,
     30, FALSE, 5, 15, 4, 5 },
};

#else
extern bot_skill_settings_t skill_settings[5];
#endif
