cycle find_cycle(elem* head) {
    cycle ans;
    ans.len = -1;
    ans.start = -1;
    if (head == nullptr) {
        ans.start = 0;
        return ans;
    }
    elem* tortoise = head;
    elem* hare = tortoise->next;
    int len = 0;
    bool is_cycle = false;
    while (hare) {
        if (!(hare->next)) {
            break;
        }
        tortoise = tortoise->next;
        hare = hare->next->next;
        if (tortoise == hare) {
            is_cycle = true;
            tortoise = tortoise->next;
            len++;
            while (hare != tortoise) {
                tortoise = tortoise->next;
                len++;
            }
            break;
        }
    }
    if (is_cycle) {
        ans.len = len;
        tortoise = head;
        hare = head;
        int index = 0;
        for (int i = 0; i < len; i++) {
            hare = hare->next;
        }
        while (hare != tortoise) {
            tortoise = tortoise->next;
            hare = hare->next;
            index++;
        }
        ans.start = index;
    }
    else {
        elem* element = head;
        while (element) {
            element = element->next;
            len++;
        }
        ans.start = len;
    }
    return ans;
}