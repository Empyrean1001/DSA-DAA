class Solution(object):
    def carFleet(self, target, position, speed):
        time_dict = {}
        for i, j in zip(position, speed):
            dist = target-i
            time_dict[dist] = float(dist)/float(j)
        dist_time = sorted(time_dict.items(), key = lambda x: x[0])
        print(dist_time)
        fleet = []
        # fleet_time = 0
        # for i in range(0,len(dist_time)-1):
        #     if dist_time[i+1][1] > dist_time[i][1] and dist_time[i+1][1] > fleet_time:
        #         # print(dist_time[i])
        #         fleet += 1
        #         fleet_time = max(dist_time[i+1][1], fleet_time)
        #     else:
        #         fleet_time = max(dist_time[i+1][1], dist_time[i][1], fleet_time)
        for d,t in dist_time:
            if not fleet or fleet[-1] < t:
                fleet.append(t)
            # print(fleet_time)

        return len(fleet)

    def carFleetOpt(self, target, position, speed):
        time = []
        for i, j in zip(position, speed):
            t = (target-i)/j
            time.append([i, t])
        
        fleet = []
        for p,t in sorted(time)[::-1]:
            if not fleet or fleet[-1] < t:
                fleet.append(t)

        return len(fleet)
