//

//  Coding
//
//  Created by Surya Dheeshjith on 05/08/19.
//  Copyright © 2019 Surya Dheeshjith. All rights reserved.

// Comparator

static int comparator(Player a, Player b)  {
        if(a.score<b.score)
        return -1;

        else if(a.score==b.score)
        {
            int i;
            for(i=0;a.name[i]!=NULL&&b.name[i]!=NULL;i++)
            {
                if(a.name[i]==b.name[i])
                continue;
                else if(a.name[i]<b.name[i])
                return 1;
                else
                return -1;
            }
            if(a.name[i]!=NULL)
            return -1;

            if(b.name[i]!=NULL)
            return 1;
            
            return 0;
        }
        else
        return 1;
}
