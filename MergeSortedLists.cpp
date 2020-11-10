SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {

    if (head1 == NULL && head2 == NULL) {
        return NULL;
    }

    if (head1 == NULL) {
        return head2;
    }

    if (head2 == NULL) {
        return head1;
    }

    // Ensure that list A starts with the smaller number
    if (head1->data > head2->data) {
        SinglyLinkedListNode *tmp = head2;
        head2 = head1;
        head1 = tmp;
    }

    SinglyLinkedListNode *listHead = head1;

    while (head2) {
        // Advance through nodes in list A until the next node
        // has data bigger than data at current node of list B
        while (head1->next != NULL &&
               head2->data > head1->next->data) {
            head1 = head1->next;
        }

        // Insert current node in list B into list A
        SinglyLinkedListNode* next = head2->next;
        head2->next = head1->next;
        head1->next = head2;
        head2 = next;
    }

    return listHead;
}