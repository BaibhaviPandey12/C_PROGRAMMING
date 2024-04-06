#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TEAMS 10
#define MAX_PLAYERS 20
#define MAX_DATE_LEN 11
struct player
{
    char name[50];
};
struct team
{
    char name[50];
    struct player players[MAX_PLAYERS];
    int num_players;
};
struct match
{
    char team1[50];
    char team2[50];
    char date[MAX_DATE_LEN];
};
//Update Teams
void update_team() {
    char team_name[50];
    printf("Enter team name to update: ");
    scanf("%s", team_name);
    //open the file in read and write mode

    FILE *fp = fopen("teams.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    struct team t;
    while (fread(&t, sizeof(struct team), 1, fp)) 
    {
        //if  the team is found in the file,user will write new team information
        if (strcmp(t.name, team_name) == 0) {
            printf("Enter new team name: ");
            scanf("%s", t.name);
            printf("Enter number of players: ");
            scanf("%d", &t.num_players);
            printf("Enter player names: ");
            for (int i = 0; i < t.num_players; i++)
            {
                scanf("%s", t.players[i]);
            }

            //overwrite the old team information with the new team information
            fseek(fp, -sizeof(struct team), SEEK_CUR);
            fwrite(&t, sizeof(struct team), 1, fp);
            fclose(fp);
            printf("Team updated successfully.\n");
            return;
        }
    }
    fclose(fp);
    printf("Team not found.\n");
}


//Display Teams
void display_teams()
{
    FILE *fp;
    struct team t;//STRUCTURE Variable to store team data 
    fp = fopen("teams.txt", "r");  
    if (fp == NULL)
    {
    printf("Error opening file.\n");
    return;
    }
    printf("List of teams:\n");
    printf("%-20s\t%-20s\n", "Team Name", "Players");
    printf("-------------------------------------------------\n");
    while (fread(&t, sizeof(struct team), 1, fp))
    {
        printf("%-20s\t", t.name);
        for (int i = 0; i < t.num_players; i++)
        {
        printf("%s, ", t.players[i].name);
        }
    printf("\n");
    }
    fclose(fp);
}
// add Teams
void add_team()
{
    FILE *fp;
    struct team t;
    fp = fopen("teams.txt", "a+");
    if (fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    printf("Enter team name: ");
    scanf("%s", t.name);
    printf("Enter number of players: ");
    scanf("%d", &t.num_players);
    printf("Enter player names:\n");
    for (int i = 0; i < t.num_players; i++)
    {
        printf("Player %d: ", i + 1);
        scanf("%s", t.players[i].name);
    }
    fwrite(&t, sizeof(struct team), 1, fp);
    printf("Team added successfully.\n");
    fclose(fp);
}
//Delete Teams
void delete_team()
{
    FILE *fp, *temp_fp;//declare two file pointers
    struct team t;//declare variable of atype struct team
    char team_name[50];
    printf("Enter name of team to delete: ");
    scanf("%s", team_name);
    fp = fopen("teams.txt", "r");
    temp_fp = fopen("temp.txt", "w");
    if (fp == NULL || temp_fp == NULL)
    {
        printf("Error opening file.\n");    
        return;
    }
    int found = 0;//initialize a variable to determine if team was found in the file
    while (fread(&t, sizeof(struct team), 1, fp))// loop through each record in the file using a while loop and the fread() function
    {
        if (strcmp(t.name, team_name) != 0)
        {
            fwrite(&t, sizeof(struct team), 1, temp_fp);
        }
        else
        {
            found = 1;//if the team name does match, set found to 1
        }
    }

    //close both files
    fclose(fp);
    fclose(temp_fp);

    //if the team was founnd in the file,  delete the original file using remove() and rename the remporary file using rename()
    if (found)
    {
        remove("teams.txt");
        rename("temp.txt", "teams.txt");
        printf("Team deleted successfully.\n");
    }
    else
    {
        remove("temp.txt");//if the team was not found, delete the temporary file
        printf("Team not found.\n");
    }
}
//Generate Schedule 
void generate_schedule()
{
    FILE *fp;
    struct team teams[MAX_TEAMS];
    struct match matches[MAX_TEAMS / 2];
    int num_teams, i, j, k = 0;
    char date[MAX_DATE_LEN];
    fp = fopen("teams.txt", "r+");
    if (fp == NULL) 
    {
        printf("Error opening file\n");
        return;
    }
    num_teams = 0;
    while (fread(&teams[num_teams], sizeof(struct team), 1, fp))
    {
        num_teams++;
    }
    fclose(fp);
    if (num_teams % 2 != 0) 
    {
        strcpy(teams[num_teams].name, "BYE");
        num_teams++;
    }
    int num_matches = num_teams - 1;
    int num_rounds = num_teams - 1;
    for (i = 0; i < num_rounds; i++)
    {
        printf("Round %d:\n", i + 1);
        for (j = 0; j < num_matches; j++)
        {
            strcpy(matches[j].team1, teams[j].name);
            strcpy(matches[j].team2, teams[num_matches - j - 1].name);
        }
        num_matches--;
        printf("%-20s\t%s\t%s\n", "Date", "Team 1", "Team 2");
        printf("-------------------------------------------------------\n");
        for (j = 0; j < num_matches; j++)
        {
            sprintf(date, "2023-05-%02d", j + 1);
            strcpy(matches[j].date, date);
            printf("%-20s\t%-20s\t%s\n", matches[j].date,matches[j].team1, matches[j].team2);   
        }
        printf("\n");
    }
    printf("Schedule generated successfully. Schedule saved to schedule.txt.\n");
    FILE *out_fp;
    out_fp = fopen("schedule.txt", "w+");
    if (out_fp == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    fprintf(out_fp, "%-20s\t%s\t%s\n", "Date", "Team 1", "Team 2");
    fprintf(out_fp,"-------------------------------------------------------\n");
    for (i = 0; i < num_matches; i++)
    {
    fprintf(out_fp, "%-20s\t%-20s\t%s\n", matches[i].date,
    matches[i].team1, matches[i].team2);
    }
    fclose(out_fp);
}
//Update Schedule
void update_schedule()
{
    FILE *fp;
    struct match matches[MAX_TEAMS / 2];
    int num_matches, i, j;
    char date[MAX_DATE_LEN];
    fp = fopen("schedule.txt", "w+");
    if (fp == NULL)
    {   
        printf("Error opening file.\n");
        return;
    }
    fseek(fp, 0, SEEK_SET);
    printf("Enter match date (YYYY-MM-DD): ");
    scanf("%s", date);
    printf("Enter number of matches: ");
    scanf("%d", &num_matches);
    for (i = 0; i < num_matches; i++)
    {
        printf("Match %d:\n", i + 1);
        printf("Enter team 1: ");
        scanf("%s", matches[i].team1);
        printf("Enter team 2: ");
        scanf("%s", matches[i].team2);
        strcpy(matches[i].date, date);
        fwrite(&matches[i], sizeof(struct match), 1, fp);
    }
    fclose(fp);
    printf("Schedule updated successfully.\n");
}
int main()
{
    int choice;
    do
    {
        printf("\n");
        printf("1. Add team\n");
        printf("2. Display teams\n");
        printf("3. Delete team\n");
        printf("4. Update_Schedule\n");
        printf("5. Update_Team\n");
        printf("6. Generate Schedule\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
            case 1:
            add_team();
            break;
            case 2:
            display_teams();
            break;
            case 3:
            delete_team();
            break;
            case 4:
            generate_schedule();
            break;
            case 5: 
            update_team();
            break;
            case 6:
            update_schedule();  
            break;
            case 7:
            printf("Goodbye!\n");
            break;
            default:
            printf("Invalid choice.\n");
            break;
        }
    } while (choice != 7);
    return 0;
}

