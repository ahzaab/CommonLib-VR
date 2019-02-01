#pragma once


namespace RE
{
	template <typename T>
	class BSTMessageQueue
	{
	public:
		virtual ~BSTMessageQueue();				// 00

		// add
		virtual bool	Push(T* a_obj) = 0;		// 01 - Wait for lock, then push
		virtual bool	TryPush(T* a_obj) = 0;	// 02 - Try for lock, return false if taken, else push
		virtual bool	Pop(T* a_obj) = 0;		// 03 - Wait for lock, then remove
		virtual bool	TryPop(T* a_obj) = 0;	// 04 - Try for lock, return false if taken, else remove
	};
	STATIC_ASSERT(sizeof(BSTMessageQueue<void*>) == 0x8);


	template <typename T>
	class BSTCommonMessageQueue : public BSTMessageQueue<T>
	{
	public:
		virtual ~BSTCommonMessageQueue();			// 00

		// override (BSTMessageQueue<T>)
		virtual bool	Push(T* a_obj) override;	// 01
		virtual bool	TryPush(T* a_obj) override;	// 02
		virtual bool	Pop(T* a_obj) override;		// 03
		virtual bool	TryPop(T* a_obj) override;	// 04

	protected:
		// add
		virtual bool	PushInternal(T* a_obj);		// 05 - { return false; }
		virtual bool	PopInternal(T* a_obj);		// 06 - { return false; }

	public:
		volatile UInt32	lock;	// 08
		volatile UInt32	pad0C;	// 0C
	};
	STATIC_ASSERT(sizeof(BSTCommonMessageQueue<void*>) == 0x10);


	template <typename T>
	class BSTCommonLLMessageQueue : public BSTCommonMessageQueue<T>
	{
	public:
		virtual ~BSTCommonLLMessageQueue();					// 00

	protected:
		// override (BSTCommonMessageQueue<T>)
		virtual bool	PushInternal(T* a_obj) override;	// 05
		virtual bool	PopInternal(T* a_obj) override;		// 06

	public:
		void*	unk10;	// 10
		UInt64	unk18;	// 18
		void*	unk20;	// 20
	};
	STATIC_ASSERT(sizeof(BSTCommonLLMessageQueue<void*>) == 0x28);


	template <typename T, std::size_t SIZE>
	class BSTCommonStaticMessageQueue : public BSTCommonMessageQueue<T>
	{
	public:
		virtual ~BSTCommonStaticMessageQueue();				// 00

	protected:
		// override (BSTCommonMessageQueue<T>)
		virtual bool	PushInternal(T* a_obj) override;	// 05
		virtual bool	PopInternal(T* a_obj) override;		// 06

	public:
		T		entries[SIZE];	// 10
		UInt32	unk1;			// ??
		UInt32	unk2;			// ??
		UInt32	unk3;			// ??
		UInt32	pad;			// ??
	};
}
