/* -*- C++ -*- */
// $Id$

// Message_Block_T.i


template<class ACE_LOCK> ACE_INLINE
ACE_Locked_Data_Block<ACE_LOCK>::ACE_Locked_Data_Block (void)
{
}

template<class ACE_LOCK> ACE_INLINE
ACE_Locked_Data_Block<ACE_LOCK>::
ACE_Locked_Data_Block (size_t size,
                       ACE_Message_Block::ACE_Message_Type msg_type,
                       const char *msg_data,
                       ACE_Allocator *allocator_strategy,
                       ACE_Message_Block::Message_Flags flags,
                       ACE_Allocator *data_block_allocator)
  : ACE_Data_Block (size,
                    msg_type,
                    msg_data,
                    allocator_strategy,
                    &lock_,
                    flags,
                    data_block_allocator)
{
}
