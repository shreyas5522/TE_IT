#include <stdio.h>
void FIFO(int no_frames, int page_no, int frame[], int page_string[])
{
    int page_faults = 0;
    int j = 0;
    int avail = 0;
    printf("*********FIFO PAGE REPLACEMENT ALGORITHM*********\n");
    printf("ref string\t\tpage frames\n");
    for (int i = 0; i < page_no; i++)
    {
        avail = 0;
        printf("%d\t\t", page_string[i]);
        for (int k = 0; k < no_frames; k++)
        {
            if (frame[k] == page_string[i])
            {
                avail = 1;
            }
        }
        if (avail == 0)
        {
            frame[j] = page_string[i];
            j = (j + 1) % no_frames;
            page_faults++;
            for (int k = 0; k < no_frames; k++)
            {
                printf("%d\t", frame[k]);
            }
        }
        printf("\n");
    }
    printf("Page fault is %d: ", page_faults);
}
void Optimal(int no_frames, int page_no, int frame[], int page_string[])
{
    int page_faults = 0;
    int flag1 = 0;
    int flag2 = 0;
    int pos = 0;
    int flag3 = 0;
    printf("*********OPTIMAL PAGE REPLACEMENT ALGORITHM*********\n");
    printf("ref string\t\tpage frames\n");
    for (int i = 0; i < page_no; i++)
    {
        flag1 = 0;
        flag2 = 0;
        for (int j = 0; j < no_frames; j++)
        {
            if (frame[j] == page_string[i])
            {
                flag2 = 1, flag1 = 1;
                break;
            }
        }
        if (flag1 == 0)
        {
            for (int j = 0; j < no_frames; j++)
            {
                if (frame[j] == -1)
                {
                    page_faults++;
                    frame[j] = page_string[i];
                    flag2 = 1;
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            flag3 = 0;
            int temp[no_frames];
            for (int m = 0; m < no_frames; m++)
            {
                temp[m] = -1;
                for (int k = i + 1; k < page_no; k++)
                {
                    if (frame[m] == page_string[k])
                    {
                        temp[m] = k;
                        break;
                    }
                }
            }
            for (int m = 0; m < no_frames; m++)
            {
                if (temp[m] == -1)
                {
                    pos = m;
                    flag3 = 1;
                    break;
                }
            }
            if (flag3 == 0)
            {
                int min = temp[0];
                for (int m = 1; m < no_frames; m++)
                {
                    if (temp[m] < min)
                    {
                        pos = m;
                        min = temp[m];
                    }
                }
            }
            frame[pos] = page_string[i];
            page_faults++;
        }
        printf("\n");
        printf("%d\t\t", page_string[i]);
        for (int k = 0; k < no_frames; k++)
        {
            printf("%d\t", frame[k]);
        }
    }
    printf("Page faults %d: ", page_faults);
}
int last_used(int time_used[], int n)
{
    int min = time_used[0];
    int pos = 0;
    for (int i = 1; i < n; i++)
    {
        if (time_used[i] < min)
        {
            pos = i;
            min = time_used[i];
        }
    }
    return pos;
}
void LRU(int no_frames, int page_no, int frame[], int page_string[])
{
    int page_faults = 0;
    int flag1 = 0;
    int pos = 0;
    int count = 0;
    int flag2 = 0;
    int time_used[10];
    printf("*********LRU PAGE REPLACEMENT ALGORITHM*********\n");
    printf("ref string\t\tpage frames\n");
    for (int i = 0; i < page_no; i++)
    {
        flag1, flag2 = 0;
        for (int j = 0; j < no_frames; j++)
        {
            if (frame[j] == page_string[i])
            {
                count++;
                time_used[j] = count;
                flag1 = 1, flag2 = 1;
                break;
            }
        }
        if (flag1 == 0)
        {
            for (int j = 0; j < no_frames; j++)
            {
                if (frame[j] == -1)
                {
                    count++;
                    time_used[j] = count;
                    flag2 = 1;
                    page_faults++;
                    frame[j] = page_string[i];
                    break;
                }
            }
        }
        if (flag2 == 0)
        {
            pos = last_used(time_used, no_frames);
            count++;
            page_faults++;
            time_used[pos] = count;
            frame[pos] = page_string[i];
        }
        printf("\n");
        printf("%d\t\t", page_string[i]);
        for (int k = 0; k < no_frames; k++)
        {
            printf("%d\t", frame[k]);
        }
    }
    printf("Page faults %d: ", page_faults);
}
int main()
{
    int page_no;
    int no_frames;
    printf("Enter the length of page string: ");
    scanf("%d", &page_no);
    int page_string[page_no];
    for (int i = 0; i < page_no; i++)
    {
        printf("Enter the string element %d: ", i);
        scanf("%d", &page_string[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &no_frames);
    int frame[no_frames];
    for (int i = 0; i < no_frames; i++)
    {
        frame[i] = -1;
    }
    int choice = 0;
    printf("\n1.LRU\n2.OPTIMAL\n3.FIFO\n");
    printf("Enter you choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        LRU(no_frames, page_no, frame, page_string);
        break;
    case 2:
        Optimal(no_frames, page_no, frame, page_string);
        break;
    case 3:
        FIFO(no_frames, page_no, frame, page_string);
        break;
    default:
        printf("Enter correct choice!!!");
    }

    return 0;
}
